#!/bin/sh

rm -rf *~
cd bin
rm -rf *
cd ..
cd build
rm -rf *

cmake ..
make
cd ..
cd bin
ls


