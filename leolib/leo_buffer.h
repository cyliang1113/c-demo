//
// Created by leo on 2020/4/28.
//

#ifndef C_BASE_DEMO_LEO_BUFFER_H
#define C_BASE_DEMO_LEO_BUFFER_H

#endif //C_BASE_DEMO_LEO_BUFFER_H
#define leo_buffer_capacity 100;
typedef struct {
    char *buffer;
    int capacity;
    int size;
    int write_p;
    int read_p;
} leo_buffer;

leo_buffer *leo_buffer_create(int buffer_capacity);

int leo_buffer_put(leo_buffer *leo_buffer, char *src, int length);

void leo_buffer_clean(leo_buffer *arr);