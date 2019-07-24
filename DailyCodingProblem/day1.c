//
// Created by adria on 24.07.2019.
//

/*
 *  Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given a string of words delimited by spaces, reverse the words in string.
    For example, given "hello world here", return "here world hello"

    Follow-up: given a mutable string representation, can you perform this operation in-place?
 */

#include "day1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Reverses a given Text whose words are separated by spaces */
char* reverseText(char *text, int length) // O(n)
{
    char* buffer = malloc(length + 1);
    char* bufferPtr = buffer;
    char *wordStart = &text[strlen(text) - 1];
    char *wordEnd = &text[strlen(text) - 1];

    while(wordStart != text) {
        wordStart--;
        if(*wordStart == ' ') {
            char *backup = --wordStart;
            wordStart++;
            do {
                *bufferPtr++ = *++wordStart;
            } while(wordStart != wordEnd);
            *bufferPtr++ = ' ';
            wordEnd = backup;
            wordStart = backup;
        }
    }
    while(wordStart != wordEnd)
        *bufferPtr++ = *wordStart++;

    *bufferPtr++ = *wordEnd;
    *bufferPtr = '\0';
    return buffer;
}


