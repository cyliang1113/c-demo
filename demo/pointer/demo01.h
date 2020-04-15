//
// Created by Youliang.Chen on 2020/4/13.
//

#ifndef C_BASE_DEMO_DEMO01_H
#define C_BASE_DEMO_DEMO01_H

#endif //C_BASE_DEMO_DEMO01_H

void pointer_def();


void arr_pointer();


void pointer_to_pointer();

void pointer_arr();

void fun_pointer(void (*p_fun_add)(), int a, int b);

void fun_add(int a, int b);

struct linked_list_node{
    int name;
    struct linked_list_node *next;
};

typedef struct linked_list_node lln;

void linked_list_demo();


