//
// Created by Youliang.Chen on 2020/4/13.
//
#include <stdio.h>
void pointer_def() {
    printf("pointer def\n");
    int num_1 = 456;

    int *p_int = &num_1;
    printf("&num_1 = %x\n", &num_1);
    printf("p_int = %x\n", p_int);
    printf("&p_int = %x\n", &p_int);
    printf("p_int sizeof = %d\n", sizeof(p_int));
    printf("*p_int = %d\n", *p_int);
    printf("p_int[0] = %d\n", p_int[0]);
    printf("&p_int[1] = %x\n", &p_int[1]);

    p_int++;
    printf("p_int++ = %x\n", p_int);
    printf("*p_int++ = %d\n", *p_int);

    p_int = p_int + 2;
    printf("p_int = %x\n", p_int);




}

void pointer_arr(){
    long l_num = 111111;
    printf("l_num sizeof = %d\n", sizeof(l_num));
    int i_num = 22;
    printf("i_num sizeof = %d\n", sizeof(i_num));
    float f_num = 3;
    printf("f_num sizeof = %d\n", sizeof(f_num));

    int arr[] = {3, 9};
    printf("arr[0] = %d\n", arr[0]);
    printf("arr sizeof = %d\n", sizeof(arr));
    printf("arr = %X\n", arr);
    printf("&arr = %X\n", &arr);
    printf("*arr = %d\n", *arr);

    int *p_arr = arr;
    printf("p_arr = %X\n", p_arr);
    printf("&p_arr[1] = %X\n", &p_arr[1]);
    printf("p_arr[0] = %d\n", p_arr[0]);
    printf("p_arr[1] = %d\n", p_arr[1]);
    float *p_arr1 = arr;
    printf("p_arr1 = %X\n", p_arr1);
    printf("&p_arr1[1] = %X\n", &p_arr1[1]);
    printf("p_arr1[0] = %d\n", p_arr1[0]);
    printf("p_arr1[1] = %d\n", p_arr1[1]);

    printf("*arr = %d\n", *arr);

    char str[] = "xyz";
    printf("*str = %c\n", *str);
    char *p_str = str;
    printf("*p_str = %c\n", *p_str);
    p_str++;
    printf("*p_str1 = %c\n", *p_str);


}
