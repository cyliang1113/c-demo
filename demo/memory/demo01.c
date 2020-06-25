//
// Created by leon on 2020/6/25.
//

#include "demo01.h"
#include <stdio.h>
#include <stdlib.h>

void fun1(){

}

int aa = 1;

void memory_addr01(){
    printf("fun1 addr: %p\n", fun1); //代码段
    printf("aa addr: %p\n", &aa); //数据段
    int bb = 1;
    int cc = 1;
    static int dd = 1;
    printf("bb addr: %p\n", &bb); //栈 是倒着的
    printf("cc addr: %p\n", &cc); //栈
    printf("dd addr: %p\n", &dd); //数据段
    int *pp = malloc(sizeof(int));
    printf("pointer pp: %p\n", pp); //堆
}
