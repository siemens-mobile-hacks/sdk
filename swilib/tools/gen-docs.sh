#!/bin/bash
set -e
set -x

cd $(dirname $0)/../
doxygen -q Doxyfile
