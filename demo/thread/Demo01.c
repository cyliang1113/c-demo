//
// Created by Youliang.Chen on 2020/6/18.
//

#include "Demo01.h"

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

//int count = 0;

void *run(void *args) {
    printf("run...\n");
    for (int i = 0; i < 2500; i++) {
//        *(int *) args = (*(int *) args) + 1;
//        printf("run count: %d\n", *(int *) args);
//        count++;
//
//        printf("run count: %d\n", count);
    }
}

struct p{
    int i;
    int *sum;
};


void *run2(void *args) {

    struct p *s_p = (struct p *)args;

    printf("(T-%d)111\n", s_p->i);
    printf("(T-%d)222\n", s_p->i);

//    (*(s_p->sum))++;
//    printf("(T-%d)sum:%d\n", s_p->i, *(s_p->sum));
}

void create_thread01(){

    int *sum = malloc(sizeof(int));
    *sum = 0;

    for (int i = 0; i < 30; i++) {
        struct p *s_p = malloc(sizeof(struct p));
        s_p->i = i;
        s_p->sum = sum;
        pthread_t thread;
        pthread_create(&thread, NULL, run2, (void *)s_p);
//        printf("create_r = %d\n", create_r);
    }
    pthread_exit(NULL);

}


