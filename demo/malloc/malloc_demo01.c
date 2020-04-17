//
// Created by leon on 2020/4/13.
//
#include <stdio.h>
#include <stdlib.h>

#define len 5

void malloc_1() {
    char *s = malloc(len * sizeof(char));
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
    free(s);
    return;
}

void calloc_1() {
    int *p_int = calloc(len, sizeof(int));
    if (p_int == NULL) {
        printf("calloc fault\n");
        return;
    }
    for (int i = 0; i < len; i++) {
        printf("s + %d = %c\n", i, *(p_int + i));
    }
    *p_int = 111;
    *(p_int + 1) = 222;
    *(p_int + 2) = 333;
    for (int i = 0; i < len; i++) {
        printf("p_int + %d = %d\n", i, *(p_int + i));
    }
    free(p_int);
}
