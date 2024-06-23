# implementation-test
Alejandro Franco Cedeño 
Job application: R19775 Software Development Engineer

# version control
```bash
file create | <commit description>
file update | <commit description>
file delete | <commit description>
```

## Compilation
```bash
g++ -o employee_utility src/*.cpp -I include
```

# Running
```bash
./scripts/run.sh data/input.xml # input data goes inside /data folder
./scripts/run.sh data/input.json
```

> View demo

# Testing
```bash
./scripts/run_tests
```
# Folder Arch
implementation-test/
├── src/
│   └──  main.cpp
├── include/
│   └── nlohmann/
│       └── employee.h
├── data/
│   ├── input.json
│   ├── input2.json
│   ├── input.xml
│   └── input2.xml
├── scripts/
│   └── run.sh
├── tests/
│   └── test_cases.cpp
├── build/
│   └── (compiled binaries)
├── .gitignore
├── README.md
└── CMakeLists.txt (or other build configuration file)


# Questions?
- what is a vector ?
- ifndef in .h is same as it is in C ?

# installed
```bash
sudo apt-get install libxml2-dev
```
# Reference
- https://en.cppreference.com/