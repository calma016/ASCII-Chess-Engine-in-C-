#!/bin/bash

g++ -o main main.cpp include/bitMap.cpp include/movement.cpp include/rules.cpp -std=c++11
./main
exit 0;