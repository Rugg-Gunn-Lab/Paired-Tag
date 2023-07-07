#!/usr/bin/env bash
mkdir -p $PREFIX/bin
cd $RECIPE_DIR
g++ -std=c++0x -pthread \
  main.cpp \
  cxstring.cpp \
  readgenome.cpp \
  reachtools.cpp \
  -o $PREFIX/bin/reachtools

