#!/bin/bash

# Compile the test cases
g++ -c src/functions.cpp -o functions.o -I/usr/include/libxml2 -lxml2
g++ -c tests/test_cases.cpp -o test_cases.o -I/usr/include/libxml2 -lxml2
g++ functions.o test_cases.o -o test_cases -I/usr/include/libxml2 -lxml2

# Run the test cases
rm *.o
./test_cases
