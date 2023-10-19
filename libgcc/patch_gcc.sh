#!/bin/bash
GCC_DIR=$1
sed 's/__attribute__((pcs("aapcs")))//g' -i $GCC_DIR/libgcc/config/arm/bpabi-lib.h
perl -0777 -p -i -e 's/#ifdef __ARM_EABI__(\n.macro\s+WEAK)/#if 1$1/gsi' $GCC_DIR/libgcc/config/arm/lib1funcs.S
