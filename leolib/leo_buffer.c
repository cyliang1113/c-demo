//
// Created by leo on 2020/4/28.
//

#include "leo_buffer.h"
#include <stdlib.h>
#include <string.h>

leo_buffer *leo_buffer_create(int buffer_capacity){
    leo_buffer *buffer = (leo_buffer *) malloc(sizeof(leo_buffer));
    buffer->capacity = buffer_capacity;
    buffer->buffer = (char *) malloc(sizeof(char) * buffer_capacity);
    buffer->read_p = 0;
    buffer->write_p = 0;
    buffer->size = 0;
    return buffer;
}

/**
 * 对齐
 * @param leo_buffer
 */
void do_align(leo_buffer *leo_buffer) {
    if (leo_buffer->size == 0) {
        leo_buffer->read_p = 0;
        leo_buffer->write_p = 0;
        return;
    }
    if (leo_buffer->read_p != 0) {
        memmove(leo_buffer->buffer, leo_buffer->buffer + leo_buffer->read_p, leo_buffer->size);
        leo_buffer->read_p = 0;
        leo_buffer->write_p = leo_buffer->size;
    }
}

void do_put(leo_buffer *leo_buffer, char *src, int length) {
    memcpy((leo_buffer->buffer + leo_buffer->write_p), src, length);
    leo_buffer->size = leo_buffer->size + length;
    leo_buffer->write_p = leo_buffer->write_p + length;
}

int leo_buffer_put(leo_buffer *leo_buffer, char *src, int length) {
    int free = leo_buffer->capacity - leo_buffer->size;
    if (length > free) {
        return -1;
    }
    do_align(leo_buffer);
    do_put(leo_buffer, src, length);
    return 1;
}

void do_get(leo_buffer *leo_buffer, char *dest, int length) {
    memcpy(dest, (leo_buffer->buffer + leo_buffer->read_p), length);
    leo_buffer->size = leo_buffer->size - length;
    leo_buffer->read_p = leo_buffer->read_p + length;
}

int leo_buffer_get(leo_buffer *leo_buffer, char *dest, int length) {
    int get_len = length;
    if (leo_buffer->size < length) {
        get_len = leo_buffer->size;
    }
    do_get(leo_buffer, dest, get_len);
    return get_len;
}


void leo_buffer_clean(leo_buffer *leo_buffer) {
    free(leo_buffer->buffer);
    free(leo_buffer);
}
