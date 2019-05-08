//
//  main.c
//  Aufgabe4
//
//  Created by Adrian Reimer on 08.05.19.
//  Copyright © 2019 Adrian Reimer. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define df_length 50
#define df_seperator 0

static char df_rem_ele = -df_length + 2; // remaining unused elements of the datafield
static char df_op_count = 1; // amount of operations used on the datafield
static char *df[df_length] = {df_seperator, &df_rem_ele,  [ 2 ... (df_length-1) ] = &df_op_count}; // Datafield
static char **ptr = &df[1];
static char **ptr2 = &df[0];

void assoziative_print(void);
int assoziative_set(char *key, char *element);
int assoziative_get(char *key);

int main(int argc, const char * argv[]) {
    assoziative_set("key1", "value1");
    assoziative_get("key1");
    assoziative_print();
    return 0;
}

int assoziative_set(char *key, char *element) {
    short key_space = (short)strlen(key) + 1;
    short element_space = (short)strlen(element) + 1;
    short req_space = key_space + element_space;
    df_rem_ele += req_space;
    if((**ptr + req_space) <= 0) {
        *ptr = req_space;
        ptr++;
        while(key_space > 0) {
            *ptr = *key;
            ptr++;
            key++;
            key_space--;
        }
        while(element_space > 0) {
            *ptr = *element;
            ptr++;
            element++;
            element_space--;
        }
        *ptr = 0;
        ptr++;
        *ptr = df_rem_ele + 2;
        df_op_count++;
        return 0;
    }
    return -1;
}

int assoziative_get(char *key) {
    char *pos = strstr(*ptr2,key);
    return 0;
}

void assoziative_print() {
    for (int i = 0; i < df_length; i++) {
        printf("%d \t %p \t %d \t %c\n", i, df[i], (int)df[i], (int)df[i]);
    }
}
