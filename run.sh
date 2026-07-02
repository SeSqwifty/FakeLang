#!/usr/bin/env bash
set -e

OUT="test.exe"
BUILD_DIR="build"

CXX="skm g++"
FLAGS="-std=c++17 -Wall -Wextra -O2 -pipe"

SRC_FILES="main.cpp Lexer.cpp expr.cpp parser.cpp"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

echo "Compiling..."

for file in $SRC_FILES
do
    obj="$BUILD_DIR/$(basename "$file" .cpp).o"
    $CXX $FLAGS -c "$file" -o "$obj" &
done

wait

echo "Linking..."

$CXX $FLAGS "$BUILD_DIR"/*.o -o "$OUT"

echo "Built $OUT"

./"$OUT"