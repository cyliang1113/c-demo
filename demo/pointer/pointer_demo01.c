//
// Created by Youliang.Chen on 2020/4/13.
//
#include <stdio.h>
#include <stdlib.h>
#include "pointer_demo01.h"

/**
 * 指针定义
 */
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

/**
 * 数组指针, 指向数组的指针
 */
void arr_pointer(){
    long l_num = 111111;
    printf("l_num sizeof = %d\n", sizeof(l_num));
    int i_num = 22;
    printf("i_num sizeof = %d\n", sizeof(i_num));
    float f_num = 3;
    printf("f_num sizeof = %d\n", sizeof(f_num));

    int arr[] = {3, 9};
    printf("items[0] = %d\n", arr[0]);
    printf("items sizeof = %d\n", sizeof(arr));
    printf("items = %X\n", arr);
    printf("&items = %X\n", &arr);
    printf("*items = %d\n", *arr);

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

    printf("*items = %d\n", *arr);

    char str[] = "xyz";
    printf("*str = %c\n", *str);
    char *p_str = str;
    printf("*p_str = %c\n", *p_str);
    p_str++;
    printf("*p_str1 = %c\n", *p_str);

}

/**
 * 指向指针的指针
 */
void pointer_to_pointer(){
    int num = 5;
    int *p_num = &num;
    int **pp_num = &p_num;

    printf("int num = %d\n", num);
    printf("&num = %x\n", &num);
    printf("p_num = %x\n", p_num);
    printf("&p_num = %x\n", &p_num);
    printf("pp_num = %x\n", pp_num);

    printf("*pp_num = %x\n", *pp_num);
    printf("**pp_num = %x\n", **pp_num);

}

/**
 * 指针数组 数组里每个元素是指针
 */
void pointer_arr(){
    int num_1 = 11;
    int num_2 = 22;
    printf("&num_1 = %x\n", &num_1);
    printf("&num_2 = %x\n", &num_2);

    int *arr[2] = {&num_1, &num_2}; //数组里每个元素是指针

    for (int i = 0; i < 2; i++) {
        printf("items[i] = %x\n", arr[i]);
        printf("*items[i] = %d\n", *arr[i]);
    }
}

void fun_pointer(void (* p_fun_add)(), int a, int b){
    p_fun_add(a, b);
}

void fun_add(int a, int b) {
    printf("a + b = %d", a + b);
}

void linked_list_demo() {
    lln head = {-1, NULL};
    lln *p_node = &head;
    for (int i = 0; i < 3; i++) {
        lln *p_node_1 = malloc(sizeof(lln));
        p_node_1->name = i;
        p_node_1->next = NULL;
        p_node->next = p_node_1;
        p_node = p_node_1;
    }
    p_node = head.next;
    for (;;) {
        if (p_node == NULL) {
            break;
        }
        printf("node.name = %d, ", p_node->name);
        printf("node.next = %x\n", p_node->next);
        p_node = p_node->next;
    }
}
