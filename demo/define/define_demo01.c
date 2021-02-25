//
// Created by Youliang.Chen on 2021/2/25.
//

#include "define_demo01.h"
#include <stdio.h>
#define add(a, b) ({ \
    int s; \
    s = a + b; \
    s; \
})

#define add_2(a)({ \
    int s; \
    asm( "addl $2, %%eax \n" \
    "movl %%eax, %%ebx \n"\
    :"=b"(s) \
    :"a"(a) \
    ); \
    s; \
})

int define_test1(){
    int s = add_2(1);
    printf("%d", s);
}
