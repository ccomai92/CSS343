#! /bin/bash 
# 
# command to compile c++ program with g++ compiler
# -----------------------------------------------------------
# Reference 
#	https://www.rapidtables.com/code/linux/gcc/gcc-o.html

g++ WordCount1.cpp BST.h -o WordCount1
g++ -O3 WordCount1.cpp BST.h -o WordCount1opt
g++ -O3 WordCount2.cpp Treap.h -o WordCount2

