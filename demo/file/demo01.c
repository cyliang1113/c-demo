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
        fprintf(p_file, "hello world");
        fclose(p_file);
    } else {
        printf("p_file is null\n", p_file);
    }
}

