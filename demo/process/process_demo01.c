//
// Created by leon on 2021/3/9.
//

#include "process_demo01.h"

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

void create(){
    printf("create pid: %d\n", getpid());
    int child;
    if (!(child = fork())) {
        // children
        printf("child pid: %d\n", getpid());
    } else {
        printf("farther pid: %d\n", getpid());
        wait4(child, NULL, 0, NULL);
        printf("child done\n");
    }
}