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
#include <string.h>
#include "../../leolib/leo_buffer.h"

#ifndef leo_array_list_item_type
    #define leo_array_list_item_type leo_buffer
#endif
#include "../../leolib/leo_array.h"




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
        printf("接收: %s\n", buff);
    }

    close(c_socket);
    close(s_socket);

    return;
}

void tcp_server_socket2(){
    int s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("s_socket = %d\n", s_socket);

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
//    s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    s_addr.sin_port = htons(8899);

    int bind_r = bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr));
    printf("bind_r = %d\n", bind_r);

    int listen_r = listen(s_socket, 1024);
    printf("listen_r = %d\n", listen_r);


    int c_socket = accept(s_socket, (struct sockaddr *)NULL, NULL);
    printf("c_socket = %d\n", c_socket);

    for (;;) {
        int lenLen = 4;
        int buff_len = 100;
        char buff[buff_len];
        char * datagramBody;
        //不考虑沾包问题
        int recv_len = recv(c_socket, buff, buff_len, 0);
        if (recv_len > 0) {
            int datagramHead0 = buff[0];
            int datagramHead1 = buff[1];
            int datagramHead2 = buff[2];
            int datagramHead3 = buff[3];
            int datagramLen = datagramHead0 << 24 | datagramHead1 << 16 | datagramHead2 << 8 | datagramHead3;
            int bodyLen = datagramLen - lenLen;
            datagramBody = malloc(bodyLen);
            for (int i = 0; i < recv_len - lenLen; i++) {
                datagramBody[i] = buff[lenLen + i];
            }
            printf("报长度: %d, 报文体长度: %d, 报文体: ", datagramLen, bodyLen);
            for (int i = 0; i < bodyLen; i++) {
                printf("%c", datagramBody[i]);
            }
            printf("\n");

        }

        free(datagramBody);
    }
}

/**
 * select
 */
void tcp_server_socket3(){
    int s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("s_socket = %d\n", s_socket);

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(8899);
    s_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

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

    int read_fd_count = 0;
    fd_set read_fd_set_buffer;
    FD_ZERO(&read_fd_set_buffer);
    FD_SET(s_socket, &read_fd_set_buffer);
    read_fd_count++;
    int fd_max = s_socket;

    struct timeval timeout;
    timeout.tv_sec =  0; //三秒
    timeout.tv_usec = 0;

    while (1) {
        fd_max = get_fd_max(read_fd_set_buffer, read_fd_count);
        fd_set read_fd_set = read_fd_set_buffer;

        int select_r = select(fd_max + 1, &read_fd_set, 0, 0, &timeout);

//        printf("select_r = %d\n", select_r);
        if (select_r == -1) {
            printf("select 发生错误\n");
            break;
        } else if (select_r == 0) {
//            printf("select 没有事件\n");
        } else {
            printf(">>>>>>>>>> 一次select, select_r = %d\n", select_r);
            for (int fd = 0; fd < fd_max + 1; fd++) {
                if (FD_ISSET(fd, &read_fd_set)) {
                    if (s_socket == fd) {
                        // server socket 事件
                        int c_socket = accept(fd, (struct sockaddr *)NULL, NULL);
                        printf("有客户端接入(c_socket = %d)\n", c_socket);
                        int bb = c_socket;
                        send(c_socket, (void *)&bb, sizeof(bb), 0);
                        FD_SET(c_socket, &read_fd_set_buffer);
                        read_fd_count++;
                    } else {
                        // client socket 事件
                        int buff_len = 100;
                        char buff[buff_len];
                        int read_r = read(fd, buff, buff_len);
                        if (read_r == 0 || read_r == -1) {
                            close(fd);
                            printf("有客户端退出(c_socket = %d)\n", fd);
                            FD_CLR(fd, &read_fd_set_buffer);
                            read_fd_count--;
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

        }
//        fd_max = get_fd_max(read_fd_set, read_fd_count);
    }


}

int get_fd_max(fd_set fd_set, int fd_count) {
    fd_set_item_type *bits = fd_set.__fds_bits;
    int fd_max = 0;
    int bit_1_count = 0;
    for (int i = 0;; i++) {
        fd_set_item_type item = bits[i];
        int item_len = sizeof(fd_set_item_type) * 8;
        for (int j = 0; j < item_len; j++) {
            int move = item >> j;
            int bit = move & 1;
            if (bit) {
                bit_1_count++;
                fd_max = i * item_len + j;
                if (bit_1_count == fd_count) {
                    return fd_max;
                }
            }
        }
    }
    return fd_max;
}

void tcp_server_socket4(){
    int s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("s_socket = %d\n", s_socket);

    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(8899);
    s_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

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

    int read_fd_count = 0;
    fd_set read_fd_set_buffer;
    FD_ZERO(&read_fd_set_buffer);
    FD_SET(s_socket, &read_fd_set_buffer);
    read_fd_count++;
    int fd_max = s_socket;

    leo_array_list *c_socket_buffer_array_list = leo_array_list_create(32);

    struct timeval timeout;
    timeout.tv_sec =  0; //三秒
    timeout.tv_usec = 0;

    while (1) {
        fd_max = get_fd_max(read_fd_set_buffer, read_fd_count);
        fd_set read_fd_set = read_fd_set_buffer;

        int select_r = select(fd_max + 1, &read_fd_set, 0, 0, &timeout);

//        printf("select_r = %d\n", select_r);
        if (select_r == -1) {
            printf("select 发生错误\n");
            break;
        } else if (select_r == 0) {
//            printf("select 没有事件\n");
        } else {
            printf(">>>>>>>>>> 一次select, select_r = %d\n", select_r);
            for (int fd = 0; fd < fd_max + 1; fd++) {
                if (FD_ISSET(fd, &read_fd_set)) {
                    if (s_socket == fd) {
                        // server socket 事件
                        int c_socket = accept(fd, (struct sockaddr *)NULL, NULL);
                        printf("有客户端接入(c_socket = %d)\n", c_socket);
                        int bb = c_socket;
                        send(c_socket, (void *)&bb, sizeof(bb), 0);
                        FD_SET(c_socket, &read_fd_set_buffer);
                        read_fd_count++;
                    } else {
                        // client socket 事件
                        int buff_len = 100;
                        char buff[buff_len];
                        int read_r = read(fd, buff, buff_len);
                        if (read_r == 0 || read_r == -1) {
                            close(fd);
                            printf("有客户端退出(c_socket = %d)\n", fd);
                            FD_CLR(fd, &read_fd_set_buffer);
                            read_fd_count--;
                            leo_array_list_item_type * buffer_p = leo_array_list_get(c_socket_buffer_array_list, fd);
                            if (buffer_p != NULL) {
                                free(buffer_p);
                            }
                        } else {
                            printf("接收到数据(c_socket = %d): ", fd);
                            for (int i = 0; i < read_r; i++) {
                                printf("%c", buff[i]);
                            }
                            printf("\n");
                            leo_array_list_item_type *buffer_p = leo_array_list_get(c_socket_buffer_array_list, fd);
                            if (buffer_p == NULL) {
                                buffer_p = leo_buffer_create(buff_len);
                                leo_array_list_put(c_socket_buffer_array_list, fd, buffer_p);
                            }
                            //


                        }
                    }
                }
            }

        }
//        fd_max = get_fd_max(read_fd_set, read_fd_count);
    }


}