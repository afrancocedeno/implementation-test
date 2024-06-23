#!/bin/bash

# Compile the C++ program
g++ -c src/main.cpp -o main.o -lxml2 -I/usr/include/libxml2
g++ -c src/functions.cpp -o functions.o -lxml2 -I/usr/include/libxml2
g++ -o employee_utility main.o functions.o -lxml2 -I/usr/include/libxml2

# clean up the object files
rm -rf *.o

# Run the utility with the provided input file
if [ $# -eq 1 ]; then
    ./employee_utility $1
elif [ $# -eq 0 ]; then
    echo "No arguments provided. Usage: ./run.sh <filename1>"
    exit 1
else
    echo "Too many arguments provided. Usage: ./run.sh <filename1>"
    exit 1
fi
