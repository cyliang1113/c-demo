//
// Created by Youliang.Chen on 2020/4/18.
//

#include <sys/types.h>

#ifndef C_BASE_DEMO_SOCKET_DEMO01_H
#define C_BASE_DEMO_SOCKET_DEMO01_H

#endif //C_BASE_DEMO_SOCKET_DEMO01_H


void tcp_server_socket();
void tcp_server_socket2();
void tcp_server_socket3();

typedef long int fd_set_item_type;

int get_fd_max(fd_set fd_set, int fd_count);

void tcp_server_socket4();


