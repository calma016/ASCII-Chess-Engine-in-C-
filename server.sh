#!/bin/bash

g++ -o main server.cpp include/bitMap.cpp include/movement.cpp include/rules.cpp -std=c++11
./server
exit 0;