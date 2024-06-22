#!/bin/bash

# Compile the main C++ program
g++ -o employee_utility src/main.cpp -I/usr/include/libxml2 -lxml2

# Compile the test cases
g++ -o test_cases tests/test_cases.cpp -I/usr/include/libxml2 -lxml2

# Run the test cases
./test_cases
