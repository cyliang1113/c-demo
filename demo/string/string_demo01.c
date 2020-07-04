//
// Created by Youliang.Chen on 2020/4/16.
//

#include "string_demo01.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void array_string_demo(){
    /**
     * 变量在内存中的位置 不一定按照定义时候的先后顺序
     */
    char a = 1;
    printf("a   addr: %p\n", &a);
    char yy[] = {'y', 'y'}; // 数组形式的字符串必须后面有\0, printf()打印字符串会一直打印到\0为止

    char zz[] = {'z', 'z', 'z'};
    printf("yy  addr: %p\n", yy);
    printf("zz  addr: %p\n", zz);

    printf("yy: %s\n", yy); // yy和zz内存连在一起, 没有\0一直打印到了yy
    char b = 1;
    printf("b   addr: %p\n", &b);
}

void string_demo(){
    char a = 1;
    printf("a   addr: %p\n", &a);

    char oo[] = "oo"; //栈中 自动在结尾加上\0
    char pp[] = "oo";
    char qq[] = "qq";
    printf("oo  addr: %p\n", oo);
    printf("pp  addr: %p\n", pp);
    printf("qq  addr: %p\n", qq);

    char *yy = "yy"; // 数据段中 字符串常量
    char *zz = "yy"; // yy zz指向同一个地址
    char *ww = "ww";
    printf("yy  addr: %p\n", yy);
    printf("zz  addr: %p\n", zz);
    printf("ww  addr: %p\n", ww);

    char *ee = (char *)malloc(1);
    ee[0] = 'e';
    ee[1] = 'e';
    ee[2] = 'e';
    printf("ee  addr: %p\n", ee);
    free(ee);
    char *ff = (char *)malloc(1);
    ff[0] = 'f';
    ff[1] = 'f';
    char *gg = (char *)malloc(1);

    printf("ff  addr: %p\n", ff);
    printf("gg  addr: %p\n", gg);


    printf("ee: %s\n", ee);
//    printf("yy: %s\n", yy); // yy和zz内存连在一起, 没有\0一直打印到了yy
    printf("yy: %s\n", zz); // yy和zz内存连在一起, 没有\0一直打印到了yy
    char b = 1;
    printf("b   addr: %p\n", &b);
}

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