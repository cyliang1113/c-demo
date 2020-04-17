cmake_minimum_required(VERSION 3.14)
project(c_base_demo C)

set(CMAKE_C_STANDARD 99)


add_executable(c_base_demo main.c demo/base/base_demo01.h demo/base/base_demo01.c demo/pointer/pointer_demo01.h demo/pointer/pointer_demo01.c demo/malloc/malloc_demo01.h demo/malloc/malloc_demo01.c demo/struct/demo01.c demo/struct/demo01.h demo/file/file_demo01.c demo/file/file_demo01.h demo/string/string_demo01.c demo/string/string_demo01.h)
