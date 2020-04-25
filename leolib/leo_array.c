//
// Created by leo on 2020/4/25.
//

#include "leo_array.h"
#include <stdlib.h>
#include <string.h>

void do_add(leo_array *arr, int item) {
    int *p_items = arr->items;
    p_items[arr->cur_p] = item;
    arr->cur_p = arr->cur_p + 1;
}

leo_array *leo_array_init() {
    leo_array *arr = (leo_array *) malloc(sizeof(leo_array));;
    arr->items = (int *) malloc(sizeof(int) * leo_array_int_capacity);
    arr->capacity = leo_array_int_capacity;
    arr->cur_p = 0;
    return arr;
}

void leo_array_add(leo_array *arr, int item) {
    if (arr->capacity == arr->cur_p) {
        //数组扩容
        int new_capacity = arr->capacity + leo_array_int_capacity;
        arr->items = realloc(arr->items, sizeof(int) * new_capacity);
        arr->capacity = new_capacity;
    }
    do_add(arr, item);
}

void leo_array_clean(leo_array *arr) {
    free(arr->items);
    arr->capacity = 0;
    arr->cur_p = 0;
    free(arr);
}