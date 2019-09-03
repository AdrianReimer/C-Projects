//
// Created by adrian on 01.09.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY32_H
#define DAILYCODINGPROBLEM_DAY32_H


typedef enum Color {
    red = 82,
    green = 71,
    blue = 66,
    white = 87
} Color;

typedef struct Position {
    unsigned int x;
    unsigned int y;
} Position;

typedef struct Size {
    unsigned int width;
    unsigned int height;
} Size;

void replAdjPix(Color *image, Size *size, Position location, Color c, Color repl);

#endif //DAILYCODINGPROBLEM_DAY32_H
