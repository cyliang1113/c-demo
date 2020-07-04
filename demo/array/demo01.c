//
// Created by leon on 2020/7/4.
//

#include "demo01.h"
#include <stdio.h>

/**
 * 数组越界
 */
char *p;
void array_out_bound_demo(){
    char a[2];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    a[3] = 'd';
    printf("a addr: %p\n", a);
    printf("a: %s\n", a);
    char a1[3];
    a1[0] = '1';
    a1[2] = '2';
    printf("a1 addr: %p\n", a1);
    printf("a: %s\n", a);
//    char b = '1';
//    printf("b addr: %p\n", &b);
//    char c = '1';
//    printf("c addr: %p\n", &c);
//    char d = '1';
//    printf("d addr: %p\n", &d);
//
//    p = &b;
//    printf("p addr: %p\n", &p);
//    printf("%s\n", p);
}
