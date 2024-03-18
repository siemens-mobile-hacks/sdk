#!/bin/bash
set -e
set -x

cd $(dirname $0)/../
/opt/doxygen/bin/doxygen -q Doxyfile
