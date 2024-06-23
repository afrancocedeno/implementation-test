# Implementation-test
Alejandro Franco Cedeño 
Job application: R19775 Software Development Engineer

# Demo 🍿
> View [DEMO](https://app.screencast.com/HeCXsnw3Ifnwc)  
#

## Installation
```bash
sudo apt install gcc # make sure you gave installed 

# libraries installations
sudo apt-get install libxml2-dev
sudo apt-get install nlohmann-json3-dev

# clone repository
git clone https://github.com/afrancocedeno/implementation-test.git

# set your working directory
cd implementation-test

# convert script to excecutables
chmod +x scripts/*.sh
```

# Running
```bash
./scripts/run.sh data/input.xml # input data goes inside /data folder
./scripts/run.sh data/input.json
```

# Testing
```bash
./scripts/run_tests.sh
```

# Folder Arch
```bash
implementation-test/
├── README.md
├── data
│   ├── input.json
│   ├── input.xml
│   ├── input2.json
│   └── input2.xml
├── include
│   └── employee.h
├── scripts
│   ├── run.sh
│   └── run_tests.sh
├── src
│   ├── functions.cpp
│   └── main.cpp
└── tests
    ├── data
    │   ├── json
    │   │   ├── empty_format1.json
    │   │   ├── empty_format2.json
    │   │   ├── no_format.jon
    │   │   └── no_formatjson
    │   ├── no_format
    │   └── xml
    │       ├── empty_format1.xml
    │       ├── empty_format2.xml
    │       ├── no_format.xl
    │       └── no_formatxml
    └── test_cases.cpp
```

# installed
```bash
sudo apt-get install libxml2-dev
```
# Reference
- https://en.cppreference.com/
- https://chatgpt.com/
