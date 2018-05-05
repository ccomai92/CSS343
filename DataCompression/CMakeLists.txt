cmake_minimum_required(VERSION 3.10)
project(DataCompression)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataCompression main.cpp Heap.h HuffmanTree.cpp HuffmanTree.h Node.h BitOutputStream.cpp BitOutputStream.h BitInputStream.cpp BitInputStream.h)