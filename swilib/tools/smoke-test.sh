#!/bin/bash
set -e

cd $(dirname $0)/../../

perl swilib/tools/gen-test-sources.pl

function test_swilib_gcc {
	name=$1
	defines=$2
	
	echo "Testing: $name (GCC)"
	
	arm-none-eabi-gcc -fno-builtin -Wall -Wextra -Werror -nostdinc -nostdlib \
		-I dietlibc/include -I swilib/include swilib/main.c swilib/swilib-smoke-test/*.c $defines -DSWILIB_INCLUDE_ALL -o /dev/null
}

function test_swilib_iar {
	name=$1
	defines=$2
	
	defines="$defines -D__ICCARM__=1 -D__swi= -D__arm="
	
	echo "Testing: $name (IAR)"
	
	arm-none-eabi-gcc -fno-builtin -Wall -Wextra -Werror -Wno-unknown-pragmas -nostdinc -nostdlib \
		-I dietlibc/include -I swilib/include swilib/main.c swilib/swilib-smoke-test/*.c $defines -DSWILIB_INCLUDE_ALL -o /dev/null
}

echo "------------------------------------------"

# GCC
test_swilib_gcc "SG" ""
test_swilib_gcc "SG_X75" "-DX75"
test_swilib_gcc "NSG" "-DNEWSGOLD"
test_swilib_gcc "NSG_ELKA" "-DNEWSGOLD -DELKA"

echo "------------------------------------------"

# IAR
test_swilib_iar "SG" ""
test_swilib_iar "SG_X75" "-DX75"
test_swilib_iar "NSG" "-DNEWSGOLD"
test_swilib_iar "NSG_ELKA" "-DNEWSGOLD -DELKA"

echo "------------------------------------------"

rm -r swilib/swilib-smoke-test
