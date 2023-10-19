#!/bin/bash
ROOT=$(dirname $(realpath $0))
LIB_FILE=$(realpath "$1")

set -e
set -x

OUT_FILE="$ROOT/../lib/libgcc.a"

TMP_DIR="$ROOT/libgcc_repack"
rm -rf "$TMP_DIR"
mkdir -p "$TMP_DIR"
cd "$TMP_DIR"
rm "$OUT_FILE"
ar x "$LIB_FILE"
arm-none-eabi-ar rcsD "$OUT_FILE" *
ls -lah "$OUT_FILE"
rm -rf "$TMP_DIR"
