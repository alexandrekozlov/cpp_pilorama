#!/bin/sh

c++ --std=c++17 -o generator generator.cpp

for n in *.cpp ; do
    out="$(basename "$n" '.cpp').md"
    qmd="q_$(basename "$n" '.cpp').md"
    ./generator full "$n" > "$out"
    ./generator short "$n" > "$qmd"
done
