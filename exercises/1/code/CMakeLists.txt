project(matmult)
enable_language(C)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_FLAGS "-std=c99") 
set(SRCS matmult.c)
add_executable(test.out ${SRCS})