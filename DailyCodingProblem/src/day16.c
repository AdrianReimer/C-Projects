//
// Created by adrian on 10.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This question was asked by Riot Games.

    Design and implement a HitCounter class that keeps track of requests (or hits).
    It should support the following operations:

    record(timestamp): records a hit that happened at timestamp
    total(): returns the total number of hits recorded
    range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

    Follow-up: What if our system has limited memory? -> Use a linked list (speed disadvantage)

    Better -> Use a hashmap and include the total hits in each node (memory disadvantage)
 */

#include "day16.h"
#include <time.h>
#include <stdlib.h>


Timestamp root;
static unsigned int totalHits;

static void addTimestamp (Timestamp *timestamp)
{
    static Timestamp *rootPtr = &root;
    while(rootPtr->next != NULL)
        rootPtr = rootPtr->next;
    rootPtr->next = timestamp;
}

void record(time_t time)
{
    totalHits++;
    Timestamp *timestamp = malloc(sizeof(Timestamp));
    timestamp->time = time;
    timestamp->next = 0;
    addTimestamp(timestamp);
}

unsigned int total()
{
    return totalHits;
}

unsigned int range(time_t timeLower, time_t timeUpper)
{
    unsigned int hitCount = 0;
    Timestamp *rootPtr = &root;
    while(rootPtr != NULL && rootPtr->time < timeLower)
        rootPtr = rootPtr = rootPtr->next;
    while(rootPtr != NULL && rootPtr->time <= timeUpper) {
        rootPtr = rootPtr = rootPtr->next;
        hitCount++;
    }
    return hitCount;
}




