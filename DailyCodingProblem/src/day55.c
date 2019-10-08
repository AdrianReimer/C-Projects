//
// Created by adrianreimer on 10/8/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    You are given given a list of rectangles represented by min and max x- and y-coordinates.
    Compute whether or not a pair of rectangles overlap each other.
    If one rectangle completely covers another, it is considered overlapping.

    For example, given the following rectangles:

    {
        "top_left": (1, 4),
        "dimensions": (3, 3) # width, height
    },
    {
        "top_left": (-1, 3),
        "dimensions": (2, 1)
    },
    {
        "top_left": (0, 5),
        "dimensions": (4, 3)
    }

    return true as the first and third rectangle overlap each other.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day55.h"


int
isOverlappingRect(Rectangle rect[], size_t len)
{
    if(rect == NULL) {
        fprintf(stderr, "Rectangle List should not be NULL!");
        return 0;
    }

    for(size_t i = 0; i < len; i++) {
        Point rDownPoint = rect[i].point;
        rDownPoint.x += rect[i].dim.x;
        rDownPoint.y -= rect[i].dim.y;
        for(size_t j = 0; j < len; j++) {
            if(&rect[j] != &rect[i]) {
                if((rDownPoint.x >= rect[j].point.x && rDownPoint.x <= rect[j].dim.x + rect[j].point.x) &&
                   (rDownPoint.y <= rect[j].point.y && rDownPoint.y >= rect[j].dim.y - rect[j].point.y) &&
                   (rect[i].point.x >= rect[j].point.x && rect[i].point.x <= rect[j].dim.x + rect[j].point.x) &&
                   (rect[i].point.y <= rect[j].point.y && rect[i].point.y >= rect[j].dim.y - rect[j].point.y)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
