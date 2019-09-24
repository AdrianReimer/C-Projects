//
// Created by adrianreimer on 9/24/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Bloomberg.

    Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

    For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

    Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "day46.h"

#define INT_BIT_LEN (sizeof(int) * 8)
#define CHAR_BIT_LEN (sizeof(char) * 8)


int isOneToOneRel(char *s1, char *s2)
{
    size_t s1Len = strlen(s1);
    size_t s2Len = strlen(s2);
    if(s1Len != s2Len)
        return 0;

    int charCntS1[CHAR_BIT_LEN] = {0}; // bit fields
    int charCntS2[CHAR_BIT_LEN] = {0}; // -
    for(size_t i = 0; i < s1Len; i++) {
        int charBitS1 = s1[i] % INT_BIT_LEN;
        int charBitS2 = s2[i] % INT_BIT_LEN;
        if(charCntS1[s1[i] / INT_BIT_LEN] & (1 << charBitS1))
            return 0;
        else
            charCntS1[s1[i] / INT_BIT_LEN] |= (1 << charBitS1);

        if(charCntS2[s2[i] / INT_BIT_LEN] & (1 << charBitS2))
            return 0;
        else
            charCntS2[s2[i] / INT_BIT_LEN] |= (1 << charBitS2);
    }
    return 1;
}
