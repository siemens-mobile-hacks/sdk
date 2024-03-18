#!/bin/bash
set -e
set -x

cd $(dirname $0)/../
[[ -d doxygen-awesome-css ]] || git submodule add https://github.com/jothepro/doxygen-awesome-css.git
doxygen Doxyfile
