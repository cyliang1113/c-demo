//
// Created by Youliang.Chen on 2020/4/18.
//

#include "socket_demo01.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


void tcp_server_socket(){
    int s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("s_socket = %d\n", s_socket);

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    s_addr.sin_port = htons(8899);

    int bind_r = bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr));
    printf("bind_r = %d\n", bind_r);

    int listen_r = listen(s_socket, 1024);
    printf("listen_r = %d\n", listen_r);


    int c_socket = accept(s_socket, (struct sockaddr *)NULL, NULL);
    printf("c_socket = %d\n", c_socket);

    int buff_len = 10;
    char buff[buff_len];

    for (;;) {
        int recv_len = recv(c_socket, buff, buff_len - 1, 0);
        buff[recv_len] = '\0';
        printf("%s", buff);
    }

    close(c_socket);
    close(s_socket);

    return;
}