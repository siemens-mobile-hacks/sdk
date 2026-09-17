#!/bin/bash
ROOT=$(dirname "$(realpath "$0")")
LIB_FILE=$(realpath "$1")
OUT_FILE=$(realpath -m "${2:-$ROOT/../lib/libgcc.a}")
AR_TOOL=${3:-arm-none-eabi-ar}
TMP_ROOT=$(realpath -m "${4:-$ROOT}")

set -e
set -x

TMP_DIR="$TMP_ROOT/libgcc-repack"
rm -rf "$TMP_DIR"
mkdir -p "$TMP_DIR"
mkdir -p "$(dirname "$OUT_FILE")"
cd "$TMP_DIR"
rm -f "$OUT_FILE"
"$AR_TOOL" x "$LIB_FILE"
"$AR_TOOL" rcsD "$OUT_FILE" *
ls -lah "$OUT_FILE"
rm -rf "$TMP_DIR"
