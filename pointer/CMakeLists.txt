cmake_minimum_required(VERSION 3.14)
project(pointer_demo C)

set(CMAKE_C_STANDARD 99)


add_executable(pointer_demo main.c
        demo/fun_ptr_demo.c demo/fun_ptr_demo.h)