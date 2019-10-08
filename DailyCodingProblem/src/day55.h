//
// Created by adrianreimer on 10/8/19.
//

#ifndef DAILYCODINGPROBLEM_DAY55_H
#define DAILYCODINGPROBLEM_DAY55_H

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
} Dimension;

typedef struct {
    Point point;
    Dimension dim;
} Rectangle;

int isOverlappingRect(Rectangle rect[], size_t len);

#endif //DAILYCODINGPROBLEM_DAY55_H
