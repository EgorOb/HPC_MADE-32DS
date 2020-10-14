#!/bin/bash
make
make clean
export OMP_NUM_THREADS=1
echo "OMP_NUM_THREADS=1"
./pi.exe
export OMP_NUM_THREADS=4
echo "OMP_NUM_THREADS=4"
./pi.exe
