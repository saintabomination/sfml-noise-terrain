#!/bin/bash

PROJECT_NAME="sfml-noise-terrain"
COMPILER="g++"
CLASS_DIR="src/Classes/*.cpp"
HEADER_DIR="src/Headers"
SRC_DIR="src/"
BUILD_DIR="build/"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

$COMPILER -c ${SRC_DIR}Main.cpp $CLASS_DIR
mkdir -p $BUILD_DIR
$COMPILER *.o -o ${BUILD_DIR}$PROJECT_NAME -I ${HEADER_DIR} $LIBRARIES
rm *.o
