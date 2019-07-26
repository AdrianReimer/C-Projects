//
// Created by adria on 26.07.2019.
//

/*
 *
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given two strings A and B, return whether or not A can be shifted some number of times to get B.

    For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
 */

#include "day3.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Shifts a given String to the right.
 * The falling character gets appended to the front.
 */
static void shiftString(char *A, int length)
{
    char end = A[length - 1];
    for(int i = length - 2; i >= 0; i--) {
        A[i + 1] = A[i];
    }
    A[0] = end;
}

/*
 * Checks if two Strings can be shifted in a way,
 * so they are equal in content.
 * @return 1 if Strings are equal
 */
int isShiftedEquals(char *A, char *B)
{
    if(strlen(A) != strlen(B))
        return 0;

    int length = strlen(A);
    for(int i = 0; i < length; i++) {
        if(strcmp(A, B) == 0)
            return 1;
        shiftString(A, length);
    }
    return 0;
}
