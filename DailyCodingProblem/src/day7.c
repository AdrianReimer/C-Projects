//
// Created by adrian on 01.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by LinkedIn.

    Given a string, return whether it represents a number. Here are the different kinds of numbers:

    "10", a positive integer
    "-10", a negative integer
    "10.1", a positive real number
    "-10.1", a negative real number
    "1e5", a number in scientific notation

    And here are examples of non-numbers:

    "a"
    "x 1"
    "a -2"
    "-"
 */

#include "day7.h"
#include <stdlib.h>
#include <string.h>

typedef enum State {
    sign,
    positive,
    negative
} State;

static const char *POS_INT = "a positive Integer";
static const char *NEG_INT = "a negative Integer";
static const char *POS_REAL = "a positive real number";
static const char *NEG_REAL = "a negative real number";
static const char *SCI_NOT = "a number in scientific notation";


char* numberRep(char *number)
{
    State state = sign;
    if(number != NULL) {
        const int length = strlen(number);
        if(length > 1) {
            if(state == sign) {
                if (*number == '-')
                    state = negative;
                else if (*number >= '0' && *number <= '9')
                    state = positive;
                else
                    return NULL;
            }
            switch(state) {
                case positive:
                    while(*++number != '\0') {
                        if(*number == '.')
                            return POS_REAL;
                        else if(*number == 'e')
                            return SCI_NOT;
                        else if(*number < '0' || *number > '9')
                            return NULL;
                    }
                    return POS_INT;
                    break;
                case negative:
                    while(*++number != '\0') {
                        if(*number == '.')
                            return NEG_REAL;
                        else if(*number == 'e')
                            return SCI_NOT;
                        else if(*number < '0' || *number > '9')
                            return NULL;
                    }
                    return NEG_INT;
                    break;
            }
        }
    }
    return NULL;
}
