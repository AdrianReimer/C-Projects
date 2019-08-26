//
// Created by adrian on 26.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given a string of parentheses,
    write a function to compute the minimum number of parentheses to be removed to make the string valid
    (i.e. each open parenthesis is eventually closed).

    For example, given the string "()())()", you should return 1.
    Given the string ")(", you should return 2, since we must remove all of them.
 */

#include "day27.h"


int parenthesesCheck(char *text)
{
    int parCount = 0, remPar = 0;
    while(*text != '\0') {
        if(*text == '(')
            parCount++;
        else if(*text == ')')
            parCount--;
        if(parCount < 0) {
            parCount = 0;
            remPar++;
        }
        text++;
    }
    return (remPar + parCount);
}
