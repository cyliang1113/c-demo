//
// Created by leo on 2020/4/25.
//

#include "leo_array.h"
#include <stdlib.h>

void do_add(leo_array_list *arr, leo_array_list_item_type item) {
    leo_array_list_item_type *p_items = arr->items;
    p_items[arr->cur_p] = item;
    arr->cur_p = arr->cur_p + 1;
}

leo_array_list *leo_array_list_create(int initial_capacity) {
    leo_array_list *arr = (leo_array_list *) malloc(sizeof(leo_array_list));;
    arr->items = (leo_array_list_item_type *) malloc(sizeof(leo_array_list_item_type) * leo_array_list_default_capacity);
    arr->capacity = initial_capacity;
    arr->cur_p = 0;
    arr->initial_capacity = initial_capacity;
    return arr;
}

void grow(leo_array_list *arr, int times) {
    //数组扩容
    int new_capacity = arr->capacity + (leo_array_list_default_capacity * times);
    arr->items = realloc(arr->items, sizeof(leo_array_list_item_type) * new_capacity);
    arr->capacity = new_capacity;
}

void leo_array_list_add(leo_array_list *arr, leo_array_list_item_type *item) {
    if (arr->capacity == arr->cur_p) {
        grow(arr, 1);
    }
    do_add(arr, item);
}

void leo_array_list_put(leo_array_list *arr, int index, leo_array_list_item_type *item) {
    if (index >= arr->capacity) {
        int times = ((index - (arr->capacity)) / leo_array_list_default_capacity) + 1;
        grow(arr, times);
    }
    *(arr->items + index) = item;
}

leo_array_list_item_type *leo_array_list_get(leo_array_list *arr, int index) {
    if (index >= arr->capacity) {
        return NULL;
    }
    return (arr->items + index);
}

void leo_array_list_clean(leo_array_list *arr) {
    free(arr->items);
    arr->capacity = 0;
    arr->cur_p = 0;
    free(arr);
}