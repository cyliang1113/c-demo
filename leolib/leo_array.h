//
// Created by leo on 2020/4/25.
//

#ifndef C_BASE_DEMO_LEO_ARRAY_H
#define C_BASE_DEMO_LEO_ARRAY_H

#endif //C_BASE_DEMO_LEO_ARRAY_H

struct _leo_array{
    int *items;
    int capacity;
    int cur_p;
};

#define leo_array_int_capacity 3

typedef struct _leo_array leo_array;

leo_array *leo_array_init();

void leo_array_add(leo_array *arr, int item);

void leo_array_clean(leo_array *arr);

