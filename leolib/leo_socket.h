//
// Created by leo on 2020/4/28.
//

#include "leo_buffer.h"

#ifndef C_BASE_DEMO_LEO_SOCKET_H
#define C_BASE_DEMO_LEO_SOCKET_H

#endif //C_BASE_DEMO_LEO_SOCKET_H



typedef struct {
    int fd;
    leo_buffer *buffer;
} leo_socket;


leo_socket *get_leo_socket(int fd, int buffer_capacity);

