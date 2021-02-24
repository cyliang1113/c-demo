//
// Created by Youliang.Chen on 2021/2/24.
//

#include "asm.h"

#include <stdio.h>

void asm_test1() {
    int a = 10;
    int r ;
    asm(
//            "movl %1, %0 \n"
//            :"=r"(r)
//            :"r"(a)

            "movl %%eax, %%ebx \n"
            "addl %%eax, %%ebx "
            :"=b"(r)
            :"a"(a)

            );
    printf("the result is %d\n", r);
    return;
}