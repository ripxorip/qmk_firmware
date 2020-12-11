#!/bin/bash

DFU=/mnt/c/msys64/mingw64/bin/dfu-programmer.exe

./util/docker_build.sh handwired/dactyl_manuform/5x6:ripxorip
echo 'Waiting  5 seconds for you to reset to DFU....'
sleep 5
$DFU atmega32u4 erase --force
$DFU atmega32u4 flash .build/handwired_dactyl_manuform_5x6_ripxorip.hex
$DFU atmega32u4 reset
