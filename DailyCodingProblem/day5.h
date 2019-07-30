//
// Created by adrian on 30.07.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY5_H
#define DAILYCODINGPROBLEM_DAY5_H

typedef struct Interval {
    int from;
    int to;
} Interval;

Interval* smallestInterval(Interval *intervalList, int length);

#endif //DAILYCODINGPROBLEM_DAY5_H
