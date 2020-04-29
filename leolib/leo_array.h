//
// Created by leo on 2020/4/25.
//

#ifndef C_BASE_DEMO_LEO_ARRAY_H
#define C_BASE_DEMO_LEO_ARRAY_H

#endif //C_BASE_DEMO_LEO_ARRAY_H

#ifndef leo_array_list_item_type
    #define leo_array_list_item_type int
#endif

typedef struct{
    leo_array_list_item_type *items;
    int capacity;
    int cur_p;
    int initial_capacity;
} leo_array_list;

#define leo_array_list_default_capacity 32

leo_array_list *leo_array_list_create(int initial_capacity);

void leo_array_list_add(leo_array_list *arr, leo_array_list_item_type *item);

void leo_array_list_put(leo_array_list *arr, int index, leo_array_list_item_type *item);

leo_array_list_item_type *leo_array_list_get(leo_array_list *arr, int index);

void leo_array_list_clean(leo_array_list *arr);



