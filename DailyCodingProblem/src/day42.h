//
// Created by adrianreimer on 9/18/19.
//

#ifndef DAILYCODINGPROBLEM_DAY42_H
#define DAILYCODINGPROBLEM_DAY42_H

#include <time.h>

typedef enum direction {
    Enter, Exit
} direction;

typedef struct timestamp {
    struct timestamp *next;
    time_t time;
    size_t count;
    direction direction;
} timestamp;

time_t* busiestPeriod(timestamp *list);
timestamp* addTimestamp (timestamp *root, timestamp *timestamp);

#endif //DAILYCODINGPROBLEM_DAY42_H
