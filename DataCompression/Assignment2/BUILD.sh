#! /bin/bash
# 
# command to compile c++ program with g++ compiler 
#-------------------------------------------------

g++ -o huff Huff.cpp HuffmanTree.cpp BitOutputStream.cpp BitInputStream.cpp
g++ -o puff Puff.cpp HuffmanTree.cpp BitOutputStream.cpp BitInputStream.cpp 
