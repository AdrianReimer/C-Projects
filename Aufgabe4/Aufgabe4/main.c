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

char df_rem_ele = -df_length + 2; // remaining unused elements of the datafield
char df_op_count = 1; // amount of operations used on the datafield
char *df[df_length] = {df_seperator, &df_rem_ele,  [ 2 ... (df_length-1) ] = &df_op_count}; // Datafield
char **ptr = &df[1];

void assoziative_print(void);
int assoziative_set(char *key, char *element);
int assoziative_get(char *key, char **element);

int main(int argc, const char * argv[]) {
    // insert code here...
    ptr--;
    ptr--;
    ptr--;
    printf("%p\n",ptr);
    printf("%p\n",df[1]);
    df_op_count++;
    printf("Hello, World!\n");
    printf("%d",*df[1]);
    //printf("%d\n\n",**ptr);
    assoziative_set("key1", "value1");
    assoziative_print();
    return 0;
}

int assoziative_set(char *key, char *element) {
    short key_space = strlen(key) + 1;
    short element_space = strlen(element) + 1;
    short req_space = key_space + element_space + 1;
    if((**ptr + req_space) <= 0) {
        **ptr = req_space;
        ptr++;
        while(key_space > 0) {
            **ptr = *key;
            ptr++;
            key++;
            key_space--;
        }
        while(element_space > 0) {
            **ptr = *element;
            ptr++;
            element++;
            element_space--;
        }
        **ptr = 0;
        ptr++;
    }
    return 0;
}

int assoziative_get(char *key, char **element) {
    return 0;
}

void assoziative_print() {
    for (int i = 0; i < df_length; i++) {
        printf("%d \t %d\n", i, df[i]);
    }
}
