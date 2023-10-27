#!/bin/bash
ROOT=$(dirname $(realpath $0))
TMP_DIR=/tmp/tmp-ep3-libs

rm -rf $TMP_DIR
mkdir -p $TMP_DIR/NSG $TMP_DIR/ELKA $TMP_DIR/SG $TMP_DIR/COMPAT

# SG
echo "SG libs"
cp -Pv $ROOT/../lib/*.so $TMP_DIR/SG/
cp -Pv $ROOT/../lib/SG/*.so $TMP_DIR/SG/
find $TMP_DIR/SG/ -type l -delete
cd $TMP_DIR/SG/ && zip $TMP_DIR/libs_SG.zip -r .
echo "------------------------------------------------"

# NSG
echo "NSG libs"
cp -Pv $ROOT/../lib/*.so $TMP_DIR/NSG/
cp -Pv $ROOT/../lib/NSG/*.so $TMP_DIR/NSG/
find $TMP_DIR/NSG/ -type l -delete
cd $TMP_DIR/NSG/ && zip $TMP_DIR/libs_NSG.zip -r .
echo "------------------------------------------------"

# ELKA
echo "ELKA libs"
cp -Pv $ROOT/../lib/*.so $TMP_DIR/ELKA/
cp -Pv $ROOT/../lib/NSG/*.so $TMP_DIR/ELKA/
cp -Pv $ROOT/../lib/ELKA/*.so $TMP_DIR/ELKA/
find $TMP_DIR/ELKA/ -type l -delete
cd $TMP_DIR/ELKA/ && zip $TMP_DIR/libs_ELKA.zip -r .
echo "------------------------------------------------"

# COMPAT
echo "compat libs"
cp -Pv $ROOT/../lib/legacy/*.so $TMP_DIR/COMPAT/
find $TMP_DIR/COMPAT/ -type l -delete
cd $TMP_DIR/COMPAT/ && zip $TMP_DIR/libs_compat.zip -r .
echo "------------------------------------------------"

ls -lah $TMP_DIR/libs_*.zip
