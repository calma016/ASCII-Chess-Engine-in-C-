#!/bin/bash

g++ -o client client.cpp include/bitMap.cpp include/movement.cpp include/rules.cpp -std=c++11
./client
exit 0;