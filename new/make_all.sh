#!/bin/sh

for n in *.cpp ; do
    out=`basename "$n" '.cpp'`
    c++ --std=c++17 -o "$out" "$n"
done
