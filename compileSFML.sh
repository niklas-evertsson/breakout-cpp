#!/bin/bash

PROJECT_PATH="$(pwd)"
BUILD_FILE=${PROJECT_PATH##*/}.app
SOURCE_FOLDER=src

if [ ! -d "$SOURCE_FOLDER" ]; then
    echo "Could not find $SOURCE_FOLDER, exiting..."
    exit
fi

echo "Compiling..."
g++ $SOURCE_FOLDER/*.cpp -o "$BUILD_FILE" "$@"

if [ -f "$BUILD_FILE" ]; then
    echo "Created $BUILD_FILE"
    chmod +x "$BUILD_FILE"
    echo "Executing $BUILD_FILE..."
    ./"$BUILD_FILE"
fi
