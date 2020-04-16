//
// Created by Youliang.Chen on 2020/4/16.
//

#include "demo01.h"

#include <string.h>
#include <stdio.h>

void string_len() {
    char *str = "str\0ing";
    int len = strlen(str);
    for (int i = 0; i < 20; i++) {
        printf("%c\n", *(str + i));
    }
    printf("str len = %d\n", len);
}

void string_cat() {
    char *str = "string";
    char *str1 = "_str";
    printf("str = %s\n", str);
    printf("str1 = %s\n", str1);
    strcat(str, str1);
    printf("str = %s\n", str);
    printf("str1 = %s\n", str1);
}