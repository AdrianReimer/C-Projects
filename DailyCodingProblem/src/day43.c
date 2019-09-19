//
// Created by adrianreimer on 9/19/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given a start word, an end word, and a dictionary of valid words,
    find the shortest transformation sequence from start to end such that
    only one letter is changed at each step of the sequence,
    and each transformed word exists in the dictionary.
    If there is no possible transformation, return null.
    Each word in the dictionary have the same length as start and end and is lowercase.

    For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"},
    return ["dog", "dot", "dat", "cat"].

    Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"},
    return null as there is no possible transformation from dog to cat.
    */

#include <stdlib.h>
#include <string.h>
#include "day43.h"


char** transformationSeq(char *start, char *end, char **dic, size_t dicLen)
{
    {
        size_t hasEnd = 0;
        for(size_t i = 0; i < dicLen; i++) {
            if (strcmp(dic[i], end) == 0)
                hasEnd++;
        }
        if(!hasEnd)
            return NULL;
    }

    size_t seqLen = strlen(start);
    char **seq = malloc(sizeof(char *) * (strlen(start) + 1));
    seq[0] = start;
    seq[seqLen] = end;
    for(size_t i = 1; i < seqLen; i++) {
        for(size_t j = 0; j < dicLen; j++) {
            if(strncmp(dic[j], start, seqLen - i) == 0 &&
               strcmp(dic[j] + (seqLen - i), end + (seqLen - i)) == 0) {
                seq[i] = dic[j];
                break;
            }
        }
        if(seq[i] == NULL)
            return NULL;
    }
    return seq;
}
