#!/usr/bin/env python3
"""Extend a verified function-library VKP using SDK signatures and stock ptr89."""
import argparse
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import tomllib


def read_library(path):
	try:
		text = path.read_bytes().decode("utf-8")
	except UnicodeDecodeError:
		text = path.read_bytes().decode("cp1251")
	target, base, current = None, None, 0
	entries, credits = {}, []
	for line in text.splitlines():
		line = line.strip()
		if match := re.fullmatch(r";\s*([A-Za-z0-9]+v\d+)", line):
			target = match[1]
		if line.startswith(";") and re.search(r"\(c\)|copyright|©|Details:", line, re.I):
			credits.append(line)
		if not line or line.startswith((";", "#pragma")):
			continue
		if re.fullmatch(r"\+[0-9A-Fa-f]+", line):
			current = int(line[1:], 16)
			if current:
				if base is not None and current != base:
					raise ValueError("Base VKP must contain one function table")
				base = current
			continue
		match = re.fullmatch(r"([0-9A-Fa-f]+):\s*0x([0-9A-Fa-f]{8})(?:\s*;\s*(.*))?", line)
		if not match or base is None or current != base:
			raise ValueError(f"Not a function-table row: {line}")
		offset = int(match[1], 16)
		if offset % 4 or offset >= 0x4000 or offset // 4 in entries:
			raise ValueError(f"Invalid or duplicate table offset: {match[1]}")
		entries[offset // 4] = (int(match[2], 16), match[3] or "")
	if base is None or not entries:
		raise ValueError("Base VKP contains no function table")
	return target, base, entries, credits


def parse_slots(text):
	slots = set()
	for part in text.split(","):
		bounds = part.strip().split("-")
		if len(bounds) not in (1, 2):
			raise ValueError(f"Invalid slot range: {part}")
		values = [int(value, 16) for value in bounds]
		if any(value < 0 or value > 0xFFFF or value & 0x7000 for value in values):
			raise ValueError(f"Invalid SWI number: {part}")
		start, end = values[0] & 0x7FFF, values[-1] & 0x7FFF
		if start > end:
			raise ValueError(f"Invalid slot range: {part}")
		slots.update(range(start, end + 1))
	return sorted(slots)


def scan_slots(ptr89, flash, table, platform, slots):
	groups = sorted(table["platforms"].items(), key=lambda item: len(item[1]))
	patterns, functions = [], []
	for slot in slots:
		entry = table.get(f"{slot:03X}", {})
		candidates = entry.get(platform)
		if platform not in entry:
			candidates = next((entry[group] for group, members in groups
				if platform in members and group in entry), [])
		if isinstance(candidates, str):
			candidates = [candidates]
		indexes = []
		for pattern in candidates or []:
			if not pattern.strip():
				continue
			if "%" in pattern:
				raise ValueError(f"{slot:03X}: symbolic references require a structural signature")
			indexes.append(len(patterns))
			patterns.append(pattern)
		functions.append({"id": slot, "name": entry.get(f"decl_{platform}", entry.get("decl", "")),
			"patterns": indexes})
	results = []
	for start in range(0, len(patterns), 50):
		# Unlimited direct search checks every match, unlike --swilib-patterns.
		command = [str(ptr89), "-f", str(flash), "-n", "0", "-J"]
		for pattern in patterns[start:start + 50]:
			command += ["-p", pattern]
		run = subprocess.run(command, capture_output=True, text=True, check=True)
		data = json.loads(run.stdout)
		if "error" in data:
			raise ValueError(data["error"])
		results.extend(data["patterns"])
	for function in functions:
		matches = [results[index] for index in function["patterns"]]
		addresses = sorted({match["address"] for result in matches for match in result["results"]
			if match["address"] != 0xFFFFFFFF})
		function["patterns"] = matches
		function["addresses"] = addresses
	return functions


def main():
	swilib = Path(__file__).resolve().parents[1]
	parser = argparse.ArgumentParser(description=__doc__)
	parser.add_argument("flash", type=Path)
	parser.add_argument("--platform", default="ELKA")
	parser.add_argument("--base-library", required=True, type=Path)
	parser.add_argument("--slots", required=True, help="hex slots, for example B00-B2D")
	parser.add_argument("--output", required=True, type=Path)
	parser.add_argument("--report", type=Path)
	parser.add_argument("--patterns", type=Path, default=swilib / "patterns.toml")
	parser.add_argument("--ptr89", type=Path, default=swilib.parents[1] / "ptr89/build/ptr89")
	parser.add_argument("--target", help="firmware name; default: flash filename without .bin")
	args = parser.parse_args()
	target = args.target or args.flash.stem
	base_target, base, entries, credits = read_library(args.base_library)
	if base_target and target.lower() != base_target.lower():
		raise ValueError(f"Base VKP targets {base_target}, requested {target}")
	report_path = args.report or args.output.with_suffix(".report.json")
	inputs = {path.resolve() for path in (args.flash, args.base_library, args.patterns)}
	if args.output.resolve() in inputs or report_path.resolve() in inputs | {args.output.resolve()}:
		raise ValueError("Output and report must differ from each other and the inputs")
	table = tomllib.loads(args.patterns.read_text())
	if not any(args.platform in members for members in table["platforms"].values()):
		raise ValueError(f"Unknown platform: {args.platform}")
	slots = parse_slots(args.slots)
	functions = scan_slots(args.ptr89, args.flash, table, args.platform, slots)
	result, errors = dict(entries), []
	for function in functions:
		slot, addresses = function["id"], function["addresses"]
		if len(addresses) != 1:
			errors.append(f"{slot:03X}: {len(addresses)} distinct addresses")
			continue
		address = addresses[0]
		if slot in entries and entries[slot][0] != address:
			errors.append(f"{slot:03X}: conflicts with base address 0x{entries[slot][0]:08X}")
			continue
		name = re.search(r"(\w+)\s*\(", function["name"])
		number = slot | (0x8000 if name and name[1].startswith("Ram") else 0)
		result[slot] = (address, f"{number:03X}: {function['name']}")
	report = {"target": target, "platform": args.platform, "base_entries": len(entries),
		"output_entries": len(result), "errors": errors, "functions": functions}
	report_path.write_text(json.dumps(report, indent=2) + "\n")
	if errors:
		raise ValueError("No VKP written:\n" + "\n".join(errors))
	lines = [f";{target}", ";Functions Library extended", *credits, "", f"+{base:07X}",
		"#pragma enable old_equal_ff"]
	lines += [f"{slot * 4:04X}: 0x{address:08X}   ; {comment}"
		for slot, (address, comment) in sorted(result.items())]
	lines += ["#pragma disable old_equal_ff", "+0", ""]
	with tempfile.TemporaryDirectory(prefix="swilib-", dir=args.output.parent) as temporary:
		staged = Path(temporary) / args.output.name
		staged.write_bytes("\r\n".join(lines).encode("utf-8"))
		staged.replace(args.output)
	print(f"{args.output}: {len(entries)} base entries + {len(result) - len(entries)} new entries")
	print(f"Report: {report_path}")
	return 0


if __name__ == "__main__":
	try:
		raise SystemExit(main())
	except (OSError, ValueError, KeyError, subprocess.CalledProcessError) as error:
		print(f"ERROR: {error}", file=sys.stderr)
		raise SystemExit(1)
