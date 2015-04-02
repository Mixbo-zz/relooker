#!/bin/bash
qmake -r Relooker.pro
make
sudo make install
make clean
