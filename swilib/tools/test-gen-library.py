#!/usr/bin/env python3
"""Check VKP generation with stock ptr89 and an artificial firmware image."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.dont_write_bytecode = True
script = Path(__file__).with_name("gen-library.py")
spec = importlib.util.spec_from_file_location("gen_library", script)
generator = importlib.util.module_from_spec(spec)
spec.loader.exec_module(generator)
ptr89 = script.resolve().parents[3] / "ptr89/build/ptr89"


class LibraryTest(unittest.TestCase):
	def test_slots(self):
		self.assertEqual(generator.parse_slots("B00-B02,8B11,B00"), [0xB00, 0xB01, 0xB02, 0xB11])
		for text in ("", "B02-B00", "1000", "10000", "-1", "B00-B01-B02"):
			with self.assertRaises(ValueError):
				generator.parse_slots(text)

	@unittest.skipUnless(ptr89.is_file(), "build ptr89 first")
	def test_cli_rejects_unsafe_tables(self):
		with tempfile.TemporaryDirectory() as temporary:
			folder = Path(temporary)
			flash = folder / "Testv1.bin"
			# PUSH {R4, LR}; NOP; PUSH {R4, LR}; ADDS R0, R0, #0.
			flash.write_bytes(bytes.fromhex("10B500BF10B5001C"))
			base = folder / "base.vkp"
			base.write_text(";Testv1\n;(c) Test author\n+0074000\n0000: 0xA00000F1 ; Original\n+0\n")
			patterns = folder / "patterns.toml"
			patterns.write_text('''[platforms]
ALL = ["ELKA"]
[000]
decl = "Original()"
ALL = "<A0000000>"
[001]
decl = "New()"
ALL = "10B500BF"
[002]
decl = "Ambiguous()"
ALL = "10B5"
[004]
decl = "ConflictingFallbacks()"
ALL = ["10B500BF", "10B5001C"]
[B11]
decl = "void **RamTest(void)"
ALL = "<A8000000>"
''')
			output = folder / "library.vkp"
			command = [sys.executable, str(script), str(flash), "--base-library", str(base),
				"--patterns", str(patterns), "--ptr89", str(ptr89), "--output", str(output), "--slots"]
			run = subprocess.run(command + ["001,8B11"], capture_output=True, text=True)
			self.assertEqual(run.returncode, 0, run.stderr)
			entries = generator.read_library(output)[2]
			self.assertEqual(set(entries), {0, 1, 0xB11})
			self.assertEqual(entries[0][0], 0xA00000F1)
			self.assertEqual(entries[1][0], 0xA0000001)
			self.assertIn("8B11:", entries[0xB11][1])
			self.assertIn(";(c) Test author", output.read_text())
			previous = output.read_bytes()
			for slots in ("002", "000", "003", "004"):
				run = subprocess.run(command + [slots], capture_output=True, text=True)
				self.assertEqual(run.returncode, 1, run.stderr)
				self.assertEqual(output.read_bytes(), previous)
				self.assertTrue(json.loads(output.with_suffix(".report.json").read_text())["errors"])
			run = subprocess.run(command + ["001", "--target", "Wrongv1"], capture_output=True, text=True)
			self.assertEqual(run.returncode, 1)
			self.assertEqual(output.read_bytes(), previous)
			base.write_text("+0074000\n0000: FFFFFFFF 00112233\n")
			with self.assertRaises(ValueError):
				generator.read_library(base)


if __name__ == "__main__":
	unittest.main()
