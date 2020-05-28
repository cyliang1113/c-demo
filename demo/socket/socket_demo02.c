//
// Created by Youliang.Chen on 2020/5/28.
//

#include "socket_demo02.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

/**
 * 阻塞式socket
 */
void tcp_server_socket_select() {
    int s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("s_socket = %d\n", s_socket);

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    s_addr.sin_port = htons(8899);

    int bind_r = bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr));
    printf("bind_r = %d\n", bind_r);
    if (bind_r == -1) {
        printf("bind error\n");
    }

    int listen_r = listen(s_socket, 1024);
    printf("listen_r = %d\n", listen_r);
    if (listen_r == -1) {
        printf("listen error\n");
    }

    fd_set read_fd_set;
    int fd_max = s_socket;
    struct timeval timeout;
    timeout.tv_sec = 0; //三秒
    timeout.tv_usec = 0;
    FD_ZERO(&read_fd_set);
    FD_SET(s_socket, &read_fd_set);

    while (1) {

        fd_set read_fd_set_x = read_fd_set;
        int select_r = select(fd_max + 1, &read_fd_set_x, 0, 0, &timeout);
//        printf("select_r = %d\n", select_r);
        if (select_r == -1) {
            printf("select 发生错误\n");
            break;
        } else if (select_r == 0) {
//            printf("select 没有事件\n");
            continue;
        } else {
            printf(">>>>>>>>>> 一次select, select_r = %d\n", select_r);

            int c_socket_arr_len = 100;
            int c_socket_arr[c_socket_arr_len];
            int c_socket_arr_p = 0;

            for (int fd = 0; fd < fd_max + 1; fd++) {
                if (FD_ISSET(fd, &read_fd_set_x)) {
                    if (s_socket == fd) {
                        // server socket 事件
                        int c_socket = accept(fd, (struct sockaddr *)NULL, NULL);
                        printf("有客户端接入(c_socket = %d)\n", c_socket);
                        c_socket_arr[c_socket_arr_p++] = c_socket;
                    } else {
                        // client socket 事件
                        int buff_len = 100;
                        char buff[buff_len];
                        int read_r = read(fd, buff, buff_len);
                        if (read_r == 0 || read_r == -1) {
                            FD_CLR(fd, &read_fd_set);
                            close(fd);
                            printf("有客户端退出(c_socket = %d)\n", fd);
                        } else {
                            printf("接收到数据(c_socket = %d): ", fd);
                            for (int i = 0; i < read_r; i++) {
                                printf("%c", buff[i]);
                            }
                            printf("\n");
                        }
                    }
                }
            }
            FD_ZERO(&read_fd_set_x);
            for(int i = 0; i < c_socket_arr_p; i++) {
                FD_SET(c_socket_arr[i], &read_fd_set);
                if (fd_max < c_socket_arr[i]) {
                    fd_max = c_socket_arr[i];
                }
            }
        }
    }
}