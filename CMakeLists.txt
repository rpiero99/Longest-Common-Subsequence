cmake_minimum_required(VERSION 3.19)
project(RiccardoPierini105131 C)

set(CMAKE_C_STANDARD 11)

add_executable(extractlcs main.c extractlcs.h matrix.h matrix.c utils.h utils.c operationfiles.h operationfiles.c)