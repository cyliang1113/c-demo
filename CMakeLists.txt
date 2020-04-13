cmake_minimum_required(VERSION 3.14)
project(c_base_demo C)

set(CMAKE_C_STANDARD 99)

add_executable(c_base_demo main.c demo/base/demo01.h demo/base/demo01.c demo/pointer/demo01.h demo/pointer/demo01.c demo/malloc/demo01.h demo/malloc/demo01.c)