//
// Created by Youliang.Chen on 2020/4/13.
//

#include <stdio.h>


#define PI 3.14
#define PI1 PI

#define BABE_NAME "Jack"

int add(int a, int b);

void var_demo_fun() {
    char num_1 = 97;
    printf("num_1 = %d\n", num_1);
    printf("num_1 = %c\n", num_1);
    short num_2;
    printf("num_2 = %d\n", num_2);
    printf("sizeof(double) = %d\n", sizeof(double));

    typedef int my_int;
    my_int num_3 = 456;
    printf("num_3 = %d\n", num_3);
    typeof(num_3);
    printf("sizeof(my_int) = %d\n", sizeof(my_int));

    int num_4 = 0b101;
    printf("num_4 = %d\n", num_4);

    printf("PI = %f\n", PI);
    printf("PI1 = %f\n", PI1);
    printf("BABE_NAME = %s\n", BABE_NAME);

    const int num_5 = 100;
    printf("num_5 = %d\n", num_5);

    for (int i = 0; i < 7; i++) {
        printf("i%d = %d\n", i, i);
    }

    int num_6 = 1 > 2;
    printf("num_6 = %d\n", num_6);
    int num_7 = 5 > 2;
    printf("num_7 = %d\n", num_7);

    if (1) {
        printf("if(1)\n");
    }
    if (0) {
        printf("if(0)\n");
    }
    if (3) {
        printf("if(3)\n");
    }
    if (-1) {
        printf("if(-1)\n");
    }
    if (-3) {
        printf("if(-3)\n");
    }

    int num_8 = 1 > 2 && 3 > 2;
    printf("num_8 = %d\n", num_8);
    int num_9 = 1 > 2 || 3 > 2;
    printf("num_9 = %d\n", num_9);
    int num_10 = 1 && 0;
    printf("num_10 = %d\n", num_10);
    int num_11 = 1 && -3;
    printf("num_11 = %d\n", num_11);
    int num_12 = 1 && 1;
    printf("num_12 = %d\n", num_12);

    printf("add(1, 3) = %d\n", add(1, 3));

    int num_13 = printf("return v\n");
    printf("num_13 = %d\n", num_13);


    return;
}

int add(int a, int b) {
    return a + b;
}

void input_demo_fun() {
    int age = 0;
    printf("age = ");
    scanf("%d", &age);
    printf("age = %d\n", age);
}

