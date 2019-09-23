//
// Created by adrianreimer on 9/21/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    Find an efficient algorithm to find the smallest distance (measured in number of words)
    between any two given words in a string.

    For example, given words "hello", and "world" and a text content
    of "dog cat hello cat dog dog hello cat world",
    return 1 because there's only one word "cat" in between the two words.
 */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "day44.h"


int smallestDist(char *start, char *end, char *text)
{
    if(start == NULL)
        fprintf(stderr, "start word should not be NULL!");
    if(end == NULL)
        fprintf(stderr, "end word should not be NULL!");
    if(text == NULL)
        return INT_MAX;

    int startLen = strlen(start);
    int endLen = strlen(end);
    int startCnt = 0;
    int endCnt = 0;
    int wordCnt = -1;
    int smallestWordCnt = INT_MAX;

    for(int i = 0; text[i] != '\0'; i++) {
        if(start[startCnt] == text[i])
            startCnt++;
        if(end[endCnt] == text[i])
            endCnt++;
        if(startCnt >= startLen) {
            if(((i - startLen) < 0 || text[i - startLen] == ' ') && text[i + 1] == ' ')
                wordCnt = -1;
            startCnt = 0;
        }
        if(endCnt >= endLen) {
            if (text[i - endLen] == ' ' && (text[i + 1] == '\0' || text[i + 1] == ' '))
                if(smallestWordCnt > wordCnt)
                    smallestWordCnt = wordCnt;
            endCnt = 0;
        }
        if(text[i] == ' ')
            wordCnt++;
    }
    return smallestWordCnt;
}