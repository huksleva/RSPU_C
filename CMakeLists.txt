cmake_minimum_required(VERSION 3.30)
project(RSPU_C C)

set(CMAKE_C_STANDARD 11)

add_executable(RSPU_C main.c
        AllocateMemory.h
        MatrixOperations.h)