#!/bin/bash

# Compile the C++ program
g++ -o employee_utility src/main.cpp -lxml2 -I/usr/include/libxml2

# Run the utility with the provided input file
./employee_utility $1
