//
// Created by Youliang.Chen on 2021/8/2.
//

#include "fun_ptr_demo.h"
#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int add_opt(int (*add_p) (int a, int b), int a, int b){
    return add_p(a, b);
}

void demo1(){
    int a = 1;
    int b = 2;
    int r = add_opt(add, a, b);
    printf("demo1 r = %d\n", r);
}

void demo2(){
    int (*add_ptr) (int a, int b);  //声明一个函数指针
    add_ptr = add;  //可以看出函数名就是函数指针
    int r = add_ptr(2, 3);
    printf("demo2 r = %d\n", r);
}

int (*add_asm_ptr)(int a, int b);  //函数指针

int add_asm(){
    asm(
    "xor %%eax, %%eax \n"
    "addl %%esi, %%eax \n"
    "addl %%edi, %%eax \n"
    :
    :
    :
    );
}
/*
 * 通过函数指针调用直接用汇编实现的方法,
 * 只要弄清楚函数传递参数的方式, 可以非常灵活的调用函数
 * 64位cpu, 寄存器数量多, 参数量少的时候, 直接调用寄存器传递参数
 */
void demo3(){
    add_asm_ptr = add_asm;
    int r = add_asm_ptr(2, 6);
    printf("demo3 r = %d\n", r);
}
