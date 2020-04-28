//
// Created by leo on 2020/4/28.
//

#include "leo_socket.h"
#include <stdlib.h>


leo_socket *get_leo_socket(int fd, int buffer_capacity) {
    leo_socket *lsp = (leo_socket *) malloc(sizeof(leo_socket));
    lsp->fd = fd;

    return lsp;
}