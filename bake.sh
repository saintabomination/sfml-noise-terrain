#!/bin/bash

PROJECT_NAME="sfml-noise-terrain"

g++ -c src/Main.cpp
mkdir -p build
g++ *.o -o build/$PROJECT_NAME
rm *.o
