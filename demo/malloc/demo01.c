//
// Created by leon on 2020/4/13.
//
#include <stdio.h>
#include <stdlib.h>

#define len 2

void malloc_1() {
    char *s = malloc(len);
    if (s == NULL) {
        printf("malloc fault\n");
        return;
    }
    printf("malloc success\n");
    for (int i = 0; i < len; i++) {
        printf("s + %d = %c\n", i, *(s + i));
    }
    *s = 'z';
    *(s + 1) = 'w';
    for (int i = 0; i < len; i++) {
        printf("s + %d = %c\n", i, *(s + i));
    }
    return;
}
