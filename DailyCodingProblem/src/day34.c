//
// Created by adrian on 06.09.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by MongoDB.

    Given a list of elements, find the majority element,
    which appears more than half the time (> floor(len(lst) / 2.0)).

    You can assume that such element exists.

    For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
 */

#include "day34.h"
#include <stdlib.h>
#include <stdio.h>


int majorityElement(int *list, unsigned int length)
{
    if(list == NULL)
        fprintf(stderr, "List of Elements should not be NULL!");

    for(int i = 0; i < length; i++) {
        int count = 0;
        for(int j = 0; j < length; j++) {
            if(list[i] == list[j])
                count++;
        }
        if(count >= (length / 2))
            return list[i];
    }
}
