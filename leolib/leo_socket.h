//
// Created by leo on 2020/4/28.
//

#ifndef C_BASE_DEMO_LEO_SOCKET_H
#define C_BASE_DEMO_LEO_SOCKET_H

#endif //C_BASE_DEMO_LEO_SOCKET_H



typedef struct {
    int fd;
    char *buffer;
    int capacity;
    int size;
    int write_p;
    int read_p;
} leo_socket;


leo_socket *get_leo_socket(int fd, int buffer_capacity);

