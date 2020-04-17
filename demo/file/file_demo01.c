//
// Created by Youliang.Chen on 2020/4/15.
//

#include "file_demo01.h"

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

void file_gets_demo() {
    FILE *p_file = fopen("D:/zzz.txt", "r");
    if (p_file == NULL) {
        printf("p_file is null\n", p_file);
        return;
    }
    int buf_size = 50;
    char buf[buf_size];
    printf("buf add = %x\n", &buf);

    rewind(p_file);
    for (;;) {
        char *gets_r = fgets(buf, buf_size, p_file);
        if (gets_r == NULL) {
            return;
        }
        printf("%s", buf);
    }
    fflush(p_file);
    fclose(p_file);
}

void file_seek_demo(){
    FILE *p_file = fopen("D:/zzz.txt", "r");
    if (p_file == NULL) {
        printf("p_file is null\n", p_file);
        return;
    }
    fseek(p_file, 0, SEEK_CUR);
    putchar(fgetc(p_file));

    fseek(p_file, 0, SEEK_CUR);
    putchar(fgetc(p_file));

}

void file_read_demo() {
    FILE *p_file = fopen("D:/zzz.txt", "r");
    if (p_file == NULL) {
        printf("p_file is null\n", p_file);
        return;
    }
    int buf_size = 5;
    char buf[buf_size];
    for (;;) {
        int r = fread(buf, sizeof(char), buf_size - 1, p_file);
        if (r == 0) {
            break;
        }
        buf[r] = '\0';
        printf("%s", buf);
    }
}

