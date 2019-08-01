//
// Created by adrian on 30.07.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given a set of closed intervals, find the smallest set of numbers that covers all the intervals.
    If there are multiple smallest sets, return any of them.

    For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
    one set of numbers that covers all these intervals is {3, 6}.
 */

#include "day5.h"

Interval* smallestInterval(Interval *intervalList, int length)
{
    Interval interval = {intervalList->to, intervalList->from};
    for(int i = 0; i < length; i++,intervalList++) {
        if(intervalList->from > interval.to)
            interval.to = intervalList->from;
        if(intervalList->to < interval.from)
            interval.from = intervalList->to;
    }
    return &interval;
}