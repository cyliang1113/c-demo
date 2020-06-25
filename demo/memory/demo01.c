//
// Created by leon on 2020/6/25.
//

#include "demo01.h"
#include <stdio.h>
#include <stdlib.h>

void fun1(){ //代码段

}

int aa = 1; //数据段

void memory_addr01(){
    printf("fun1 addr: %p\n", fun1);
    printf("aa addr: %p\n", &aa);
    int bb = 1; //栈 是倒着的
    int cc = 1; //栈
    static int dd = 1; //数据段 和aa在一起
    printf("bb addr: %p\n", &bb);
    printf("cc addr: %p\n", &cc);
    printf("dd addr: %p\n", &dd);
    void *pp1 = malloc(1); //堆
    printf("pointer pp1: %p\n", pp1);
    void *pp2 = malloc(1); //堆
    printf("pointer pp2: %p\n", pp2);
    void *pp3 = malloc(1); //堆
    printf("pointer pp3: %p\n", pp3);
}
