cmake_minimum_required(VERSION 3.28)
project(cfg)

set(CMAKE_CXX_STANDARD 17)

add_executable(cfg main.cpp
        CFG.cpp
        CFG.h)
