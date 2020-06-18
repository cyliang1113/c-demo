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

void *run2(void *args) {

    int *count = (int *)args;
    *count = (*count) + 1;
    printf("run2 count: %d\n", *count);
}

void create_thread01(){
//    printf("1111111111\n");
    pthread_t thread;
    pthread_t thread2;
//    printf("22222222222\n");

    int count = 0;

//    int r = pthread_create(&thread, NULL, run, (void *)count);
//    printf("pthread_create r: %d\n", r);
//    int r2 = pthread_create(&thread2, NULL, run2, NULL);
//    printf("pthread_create r2: %d\n", r2);
    for (int i = 0; i < 5; i++) {
        pthread_create(&thread2, NULL, run2, (void *)&count);
    }
    pthread_exit(NULL);
//    pthread_join(thread, &r);
//    pthread_join(thread2, &r);
//
//    printf("end\n");
}


