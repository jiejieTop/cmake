#!/bin/bash

mkdir -p build bin lib
cd build
cmake ../..
make
