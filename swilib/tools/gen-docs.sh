#!/bin/bash
set -e

export PATH="/opt/doxygen/bin/:$PATH"

cd $(dirname $0)/../
[[ -d doxygen-awesome-css ]] || git clone https://github.com/jothepro/doxygen-awesome-css --depth 1

mkdir -p html/swilib/SG
mkdir -p html/swilib/SG_X75
mkdir -p html/swilib/NSG
mkdir -p html/swilib/NSG_ELKA

function doxygen_run() {
	name=$1
	dir=$2
	defines=$3
	
	mkdir -p "html/swilib/$dir"
	
	echo "Gen docs: $dir"
	
	cp Doxyfile Doxyfile.tmp
	echo "HTML_OUTPUT=html/swilib/$dir" >> Doxyfile.tmp
	echo "PROJECT_NAME=SWILIB API $name&nbsp;&nbsp;&nbsp;&nbsp;" >> Doxyfile.tmp
	echo "PREDEFINED=SWILIB_LIBC SWILIB_LIBPNG SWILIB_ZLIB SWILIB_OPENSSL SWILIB_LEGACY_COMPAT SWILIB_MODERN __swilib_begin __swilib_end DOXYGEN $defines" >> Doxyfile.tmp
	doxygen -q Doxyfile.tmp
	rm Doxyfile.tmp

	echo "------------------------------------------------------"
}

doxygen_run "(SG)" "SG" ""
doxygen_run "(X75)" "SG_X75" "X75"
doxygen_run "(NSG)" "NSG" "NEWSGOLD"
doxygen_run "(ELKA)" "NSG_ELKA" "NEWSGOLD ELKA"
