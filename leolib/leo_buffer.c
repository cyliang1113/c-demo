//
// Created by leo on 2020/4/28.
//

#include "leo_buffer.h"
#include <stdlib.h>
#include <string.h>

leo_buffer *leo_buffer_create(int buffer_capacity){
    leo_buffer *buffer = (leo_buffer *) malloc(sizeof(leo_buffer));
    buffer->capacity = buffer_capacity;
    buffer->buffer = (leo_buffer *) malloc(sizeof(char) * buffer_capacity);
    buffer->read_p = 0;
    buffer->write_p = 0;
    buffer->size = 0;
    return buffer;
}

/**
 * 对齐
 * @param leo_buffer
 */
void leo_buffer_align(leo_buffer *leo_buffer) {
    if (leo_buffer->read_p != 0) {
        memmove(leo_buffer->buffer, leo_buffer->buffer + leo_buffer->read_p, leo_buffer->size);
        leo_buffer->read_p = 0;
        leo_buffer->write_p = leo_buffer->size;
    }
}

int leo_buffer_put(leo_buffer *leo_buffer, char *src, int length) {
    int free = leo_buffer->capacity - leo_buffer->size;
    if (length > free) {
        return -1;
    }
    leo_buffer_align(leo_buffer);
    memcpy(leo_buffer->buffer + leo_buffer->write_p, src, length);
    return 1;
}


void leo_buffer_clean(leo_buffer *leo_buffer) {
    free(leo_buffer->buffer);
    free(leo_buffer);
}
