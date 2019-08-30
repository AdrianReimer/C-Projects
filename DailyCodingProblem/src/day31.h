//
// Created by adrian on 30.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY31_H
#define DAILYCODINGPROBLEM_DAY31_H

typedef struct Point {
    int x;
    int y;
} Point;

Point* nearestPoints(Point *list, unsigned int length, Point *center, int k);

#endif //DAILYCODINGPROBLEM_DAY31_H
