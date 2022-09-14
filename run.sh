#!/bin/bash

cd build

rm *.pdb
rm *.crd
rm *.xyz

rm ../init_crd/*.crd
rm ../init_pdb/*.pdb

python make_movie.py
./replace.sh

cd ../init_crd
./remove_float.sh

cd ../
charmm -i ener.inp -o ener.out

