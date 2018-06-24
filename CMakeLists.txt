cmake_minimum_required(VERSION 3.10)
project(Graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(Graphs main.cpp Iteratable.h AdjacencyList.h Node.h)