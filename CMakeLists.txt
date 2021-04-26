cmake_minimum_required(VERSION 3.14)
project(c_demo C)

set(CMAKE_C_STANDARD 99)


add_executable(c_demo main.c demo/base/base_demo01.h demo/base/base_demo01.c
        demo/pointer/pointer_demo01.h demo/pointer/pointer_demo01.c
        demo/malloc/malloc_demo01.h demo/malloc/malloc_demo01.c
        demo/struct/demo01.c demo/struct/demo01.h
        demo/file/file_demo01.c demo/file/file_demo01.h
        demo/string/string_demo01.c demo/string/string_demo01.h
        demo/socket/socket_demo01.c demo/socket/socket_demo01.h
        leolib/leo_array.c leolib/leo_array.h
        leolib/leo_socket.c leolib/leo_socket.h
        leolib/leo_buffer.c leolib/leo_buffer.h
        demo/socket/socket_demo02.c demo/socket/socket_demo02.h
        demo/thread/Demo01.c demo/thread/Demo01.h
        demo/memory/demo01.c demo/memory/demo01.h
        demo/asm/asm.c demo/asm/asm.h
        demo/define/define_demo01.c demo/define/define_demo01.h
        demo/process/process_demo01.c demo/process/process_demo01.h
        )


find_package(Threads REQUIRED)
target_link_libraries(c_demo Threads::Threads)