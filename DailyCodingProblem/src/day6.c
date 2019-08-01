//
// Created by adrian on 31.07.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked Microsoft.

    Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.

    For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
 */

#include "day6.h"
#include <stdio.h>
#include <stdlib.h>

char* read7(char *file)
{
    static FILE *fp;
    char *phrase = malloc(sizeof(char) * 8);
    if(fp == NULL)
        fp = fopen(file, "r");
    if(fp == NULL)
        fprintf(stderr, "File not found!\n");
    for(int i = 0; i < 7; i++)
        phrase[i] = getc(fp);
    phrase[7] = '\0';
    return phrase;
}

char* readN(char *file, unsigned int count)
{
    static FILE *fp;
    char *phrase = malloc(sizeof(char) * count);
    if(fp == NULL)
        fp = fopen(file, "r");
    if(fp == NULL)
        fprintf(stderr, "File not found!\n");
    for(int i = 0; i < count - 1; i++)
        phrase[i] = getc(fp);
    phrase[count - 1] = '\0';
    return phrase;
}
