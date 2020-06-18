//
// Created by Youliang.Chen on 2020/6/18.
//

#include "Demo01.h"
#include <stdio.h>
//#include <stdlib.h>

#include <pthread.h>

void *run(void *args) {
    printf("run... \n");
//    for (int i = 0; i < 5; i++) {
//        *(int *) args = *(int *) args + 1;
//        printf("thread count: %d\n", *(int *) args);
//    }
}

void create_thread01(){
//    printf("1111111111\n");
    pthread_t *thread;

//    printf("22222222222\n");
//    void *count = malloc(sizeof(int));
//    *count = 1;

//    printf("33333333333\n");
    int r = pthread_create(thread, NULL, run, NULL);
    printf("pthread_create r: %d\n", r);

//    for (int j = 0; j < 5; j++) {
//        *count = *count + 1;
//        printf("main count: %d\n", *count);
//    }
}


