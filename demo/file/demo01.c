//
// Created by Youliang.Chen on 2020/4/15.
//

#include "demo01.h"

void open_file_demo(){
    FILE *p_file = fopen("D:/zzz.txt", "r");
//    FILE *p_file = fopen("D:/zzz1.txt", "r");
    printf("p_file = %x\n", p_file);
    if (p_file != NULL) {
        printf("p_file not null\n", p_file);
        fclose(p_file);
    } else {
        printf("p_file is null\n", p_file);
    }
}

void write_file_demo(){
    FILE *p_file = fopen("D:/zzz.txt", "w");
    if (p_file != NULL) {
        printf("p_file not null\n", p_file);
        fprintf(p_file, "hello world !!!");
        fflush(p_file);
        fclose(p_file);
    } else {
        printf("p_file is null\n", p_file);
    }
}

void read_file_demo() {
    FILE *p_file = fopen("D:/zzz.txt", "r");
    if (p_file == NULL) {
        printf("p_file is null\n", p_file);
        return;
    }
    int buf_size = 5;
    char buf[buf_size];
    int orig = 0;
    int off = buf_size - 1;
    rewind(p_file);
    for (;;) {
        char *gets_r = fgets(buf, buf_size, p_file);
        if (gets_r == NULL) {
            return;
        }
        printf("%s", buf);
//        printf("%s", buf);
        orig = orig + off;
        int seek_r = fseek(p_file, orig, off);
//        printf("%d\n", seek_r);
    }
    fflush(p_file);
    fclose(p_file);
}

