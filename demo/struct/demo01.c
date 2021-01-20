//
// Created by Youliang.Chen on 2020/4/14.
//
#include <stdio.h>
#include "demo01.h"

void struct_def(){
    struct person{
        int age;
        int height;
    };

    struct person tom = {25, 178};

    printf("person.age = %d\n", tom.age);
    printf("person.height = %d\n", tom.height);

    struct person *p_tom = &tom;
    printf("p_tom->age = %d\n", p_tom->age);
    printf("p_tom->height = %d\n", p_tom->height);
    printf("*p_tom.age = %d\n", (*p_tom).age);
    printf("*p_tom.height = %d\n", (*p_tom).height);

}

struct person{
    char *name;
    int age;
};

void print(struct person pn) {
    printf("pn addr = %x\n", &pn);
    printf("person.name = %s\n", pn.name);
    printf("person.age = %d\n", pn.age);
    pn.name = "Google";
}

void fun_args_struct(){
    struct person p = {"name", 28};
    printf("p addr = %x\n", &p);
    print(p);
}

void fun_args_struct_pointer(struct person *p_pn) {
    printf("p_pn = %x\n", p_pn);
    printf("p_pn->name = %s\n", p_pn->name);
    printf("p_pn->age = %d\n", p_pn->age);
    p_pn->name = "Apple";
}

void struct_arr() {
    struct person arr[2] = {{"Tom", 25}, {"Jack", 28}};
    for (int i = 0; i < 1; i++) {
        printf("items[i] addr = %x\n", &arr[i]);
        struct person item = arr[i];
        printf("item addr = %x\n", &item);
//        fun_args_struct_pointer(&item);
        print(item);
        printf("%s\n", item.name);
    }
}

struct struct_man{
    char *name;
    int age;
};

typedef struct struct_man Man;

void struct_test01(){
    Man man;
    man.name = "Tom";
    man.age = 18;
    printf("man.name: %s\n", man.name);
    printf("man.age: %d\n", man.age);

}

void struct_test02(){
    Man man;
    man.name = "Tom";
    man.age = 18;
    printf("man.name: %s\n", man.name);
    printf("man.age: %d\n", man.age);
    printf("man add: %p\n", &man);
    printf("man.name add: %p\n", &(man.name));
    printf("man.age add: %p\n", &(man.age));

    Man man1 = man;
    printf("man1.name: %s\n", man.name);
    printf("man1.age: %d\n", man.age);
    printf("man1: %p\n", &man1);
    printf("man1.name add: %p\n", &(man1.name));
    printf("man1.age add: %p\n", &(man1.age));
}