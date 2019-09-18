//
// Created by adrianreimer on 9/18/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    You are given a list of data entries that represent entries and exits of groups of people into a building.
    An entry looks like this:

    {"timestamp": 1526579928, count: 3, "type": "enter"}

    This means 3 people entered the building. An exit looks like this:

    {"timestamp": 1526580382, count: 2, "type": "exit"}

    This means that 2 people exited the building. timestamp is in Unix time.

    Find the busiest period in the building, that is, the time with the most people in the building.
    Return it as a pair of (start, end) timestamps.
    You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
 */

#include <stdlib.h>
#include "day42.h"


time_t* busiestPeriod(timestamp *list)
{
    time_t *busiestTime = malloc(sizeof(time_t) * 2);
    size_t maxPeople = 0;
    size_t peopleCount = 0;
    timestamp *busiestPeriod = list;
    while(list->next != NULL) {
        if(list->direction == Enter)
            peopleCount += list->count;
        else
            peopleCount -= list->count;
        if(peopleCount > maxPeople) {
            maxPeople = peopleCount;
            busiestPeriod = list;
        }
        list = list->next;
    }
    busiestTime[0] = busiestPeriod->time;
    busiestPeriod = busiestPeriod->next;
    busiestTime[1] = busiestPeriod->time;
    return busiestTime;
}

timestamp* addTimestamp(timestamp *root, timestamp *timestamp)
{
    while(root->next != NULL)
        root = root->next;
    root->next = timestamp;
}
