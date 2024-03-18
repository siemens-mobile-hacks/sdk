#!/bin/bash
set -e
set -x

export PATH="/opt/doxygen/bin/:$PATH"

cd $(dirname $0)/../
[[ -d doxygen-awesome-css ]] || git submodule add https://github.com/jothepro/doxygen-awesome-css.git

PREDEFINED="SWILIB_LIBC SWILIB_LIBPNG SWILIB_ZLIB SWILIB_OPENSSL SWILIB_LEGACY_COMPAT SWILIB_MODERN __swilib_begin __swilib_end DOXYGEN"
PROJECT_NAME="SWILIB API"

mkdir -p html/swilib/SG
mkdir -p html/swilib/SG_X75
mkdir -p html/swilib/NSG
mkdir -p html/swilib/NSG_ELKA

( cat Doxyfile ; echo "HTML_OUTPUT=html/swilib/SG"; echo "PREDEFINED=$PREDEFINED"; echo "PROJECT_NAME=$PROJECT_NAME (SG)&nbsp;&nbsp;&nbsp;&nbsp;" ) | doxygen -
( cat Doxyfile ; echo "HTML_OUTPUT=html/swilib/SG_X75"; echo "PREDEFINED=$PREDEFINED X75"; echo "PROJECT_NAME=$PROJECT_NAME (X75)&nbsp;&nbsp;&nbsp;&nbsp;" ) | doxygen -
( cat Doxyfile ; echo "HTML_OUTPUT=html/swilib/NSG"; echo "PREDEFINED=$PREDEFINED NEWSGOLD"; echo "PROJECT_NAME=$PROJECT_NAME (NSG)&nbsp;&nbsp;&nbsp;&nbsp;" ) | doxygen -
( cat Doxyfile ; echo "HTML_OUTPUT=html/swilib/NSG_ELKA"; echo "PREDEFINED=$PREDEFINED NEWSGOLD"; echo "PROJECT_NAME=$PROJECT_NAME (ELKA)&nbsp;&nbsp;&nbsp;&nbsp;" ) | doxygen -
