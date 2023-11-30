#!/bin/bash

rm -rf ./build ./install
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install -G Ninja
ninja -C build install
