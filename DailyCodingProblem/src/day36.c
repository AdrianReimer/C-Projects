//
// Created by adrian on 08.09.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given a string, return the first recurring character in it, or null if there is no recurring character.

    For example, given the string "acbbac", return "b". Given the string "abcdef", return null.
 */

#include "day36.h"
#include <string.h>


char recurChar(char *text)
{
    if(text == NULL)
        return NULL;

    int textLen = strlen(text);
    char c = 0;
    for(int i = 0; i < textLen; i++) {
        if(text[i] < c)
            return text[i];
        c = text[i];
    }
    return NULL;
}
