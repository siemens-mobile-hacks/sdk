#!/bin/bash
ROOT=$(dirname $(realpath $0))
TMP_DIR=/tmp/tmp-ep3-libs

rm -rf $TMP_DIR
mkdir -p $TMP_DIR/NSG $TMP_DIR/ELKA $TMP_DIR/SG

# SG
echo "SG libs"
cp -v $ROOT/../lib/*.so $TMP_DIR/SG/
cp -v $ROOT/../lib/SG/*.so $TMP_DIR/SG/
cd $TMP_DIR/SG/ && zip $TMP_DIR/libs_SG.zip -r .
echo "------------------------------------------------"

# NSG
echo "NSG libs"
cp -v $ROOT/../lib/*.so $TMP_DIR/NSG/
cp -v $ROOT/../lib/NSG/*.so $TMP_DIR/NSG/
cd $TMP_DIR/NSG/ && zip $TMP_DIR/libs_NSG.zip -r .
echo "------------------------------------------------"

# ELKA
echo "ELKA libs"
cp -v $ROOT/../lib/*.so $TMP_DIR/ELKA/
cp -v $ROOT/../lib/NSG/*.so $TMP_DIR/ELKA/
cp -v $ROOT/../lib/ELKA/*.so $TMP_DIR/ELKA/
cd $TMP_DIR/ELKA/ && zip $TMP_DIR/libs_ELKA.zip -r .
echo "------------------------------------------------"

ls -lah $TMP_DIR/libs_*.zip
