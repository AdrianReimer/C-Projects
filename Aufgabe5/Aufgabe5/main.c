//
//  main.c
//  Aufgabe5
//
//  Created by Adrian Reimer on 20.05.19.
//  Copyright © 2019 Adrian Reimer. All rights reserved.
//

#include <stdio.h>

typedef struct xyz align_field;

struct xyz {
    char a;
    short b;
    int c;
    char arr[5];
    float d;
    double e;
};

void print_address_offset(align_field *var) {
    void *ptr = var;
    printf("%p \t %c\n",ptr,*(char *)ptr);
    ptr += sizeof(char) + 1; // 1 alignment byte
    printf("%p \t %d\n",ptr,*(short *)ptr);
    ptr += sizeof(short);
    printf("%p \t %d\n",ptr,*(int *)ptr);
    ptr += sizeof(int);
    printf("%p \t %c\n",ptr,*(char *)ptr);
    ptr += sizeof(char[5]) + 3; // 3 alignment bytes
    printf("%p \t %f\n",ptr,*(float *)ptr);
    ptr += sizeof(float) + 4; // 4 alignment bytes
    printf("%p \t %f\n\n",ptr,*(double *)ptr);
}

void print_bytewise_float(float *var) {
    void *ptr = var;
    int i;
    for(i = 0; i < sizeof(float); i++) {
        printf("%p \t %hhx\n",ptr,*(char *)ptr);
        ptr++;
    }
    printf("\n");
    // ### Example
    //                  0.2
    //    cd       cc       4c       3e
    // 11001101 11001100 01001100 0111110
    //       significand          sign    exponent
    // 10011001100110011001101    0       1111100
}

void print_bytewise_double(double *var) {
    void *ptr = var;
    int i;
    for(i = 0; i < sizeof(double); i++) {
        printf("%p \t %hhx\n",ptr,*(char *)ptr);
        ptr++;
    }
    printf("\n");
    // ### Example
    //                                   0.4
    //    9a       99       99       99       99       99       d9       3f
    // 10011010 10011001 10011001 10011001 10011001 10011001 11011001 00111111
    //       significand                                sign        exponent
    // 00110011001100110011001100110011001100110011010    0       0111111110110011
}

int main(int argc, const char * argv[]) {
    align_field var = {'a',2,2,{'a','b','c','d','e'},0.2f,0.4};
    print_address_offset(&var);
    print_bytewise_float(&var.d);
    print_bytewise_double(&var.e);
    return 0;
}


