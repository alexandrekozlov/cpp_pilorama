#!/bin/sh

mkdir bin

c++ --std=c++17 -o bin/generator generator.cpp

mkdir questions
mkdir reference

for n in *.cpp ; do
    out="$(basename "$n" '.cpp').md"
    qmd="$(basename "$n" '.cpp').md"
    bin/generator full "$n" > "reference/$out"
    bin/generator short "$n" > "questions/$qmd"
done
