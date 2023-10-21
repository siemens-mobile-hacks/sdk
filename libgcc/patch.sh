#!/bin/bash
set -e
set -x
# sed -i -re 's/__dso_handle\s+__attribute__\s+\(\(__visibility__ \("hidden"\)\)\)/__dso_handle/g' $1/libgcc/crtstuff.c
