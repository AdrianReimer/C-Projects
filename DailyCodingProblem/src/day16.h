//
// Created by adrian on 10.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY16_H
#define DAILYCODINGPROBLEM_DAY16_H

#include <time.h>

typedef struct Timestamp {
    struct Timestamp *next;
    time_t time;
} Timestamp;

void record(time_t time);
unsigned int total();
unsigned int range(time_t timeLower, time_t timeUpper);

#endif //DAILYCODINGPROBLEM_DAY16_H
