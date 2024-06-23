#!/bin/bash

# Compile the C++ program
g++ -c src/main.cpp -o main.o -lxml2 -I/usr/include/libxml2
g++ -c src/functions.cpp -o functions.o -lxml2 -I/usr/include/libxml2
g++ -o employee_utility main.o functions.o -lxml2 -I/usr/include/libxml2

# Run the utility with the provided input file
./employee_utility $1
