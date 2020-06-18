//
// Created by Youliang.Chen on 2020/6/18.
//

#include "Demo01.h"

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>


void *run(void *args) {
    printf("run...\n");
    for (int i = 0; i < 50; i++) {
        *(int *) args = (*(int *) args) + 1;
        printf("run count: %d\n", *(int *) args);
    }
}

void *run2(void *args) {
    printf("run2...\n");
    for (int i = 0; i < 50; i++) {
        *(int *) args = (*(int *) args) + 1;
        printf("run2 count: %d\n", *(int *) args);
    }
}

void create_thread01(){
//    printf("1111111111\n");
    pthread_t thread;
    pthread_t thread2;
//    printf("22222222222\n");
    int *count = malloc(sizeof(int));
    *count = 0;

    int r = pthread_create(&thread, NULL, run, (void *)count);
    printf("pthread_create r: %d\n", r);
//    int r2 = pthread_create(&thread2, NULL, run2, (void *)count);
//    printf("pthread_create r2: %d\n", r2);
    pthread_join(thread, &r);
}


