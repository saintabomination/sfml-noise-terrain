#!/bin/bash

PROJECT_NAME="sfml-noise-terrain"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

g++ -c src/Main.cpp
mkdir -p build
g++ *.o -o build/$PROJECT_NAME $LIBRARIES
rm *.o
