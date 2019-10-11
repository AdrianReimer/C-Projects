//
// Created by adrianreimer on 10/11/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Stripe.

    Given a collection of intervals, find the minimum number of
    intervals you need to remove to make the rest of the intervals non-overlapping.

    Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.

    For example, given the intervals (7, 9), (2, 4), (5, 8),
    return 1 as the last interval can be removed and the first two won't overlap.

    The intervals are not necessarily sorted in any order.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day57.h"


size_t
minOverlap(Interval intervals[], size_t len)
{
    if(intervals == NULL) {
        fprintf(stderr, "intervals should not be NULL!");
        return 0;
    }

    size_t overlapCnt = 0;
    Interval *overlapInterv[len];
    for(size_t i = 0; i < len; i++) {
        for(size_t j = 0; j < len; j++) {
            if(&intervals[i] != &intervals[j]) {
                if((intervals[i].from > intervals[j].from &&
                   intervals[i].from < intervals[j].to) || (
                    intervals[i].to > intervals[j].from &&
                    intervals[i].to < intervals[j].to)) {
                        int isInList = 0;
                        for(size_t k = 0; k < overlapCnt; k++) {
                            if(&intervals[j] == overlapInterv[k] ||
                               &intervals[i] == overlapInterv[k]) {
                                isInList = 1;
                                break;
                            }
                        }
                        if(!isInList)
                            overlapInterv[overlapCnt++] = &intervals[j];
                }
            }
        }
    }
    return overlapCnt;
}