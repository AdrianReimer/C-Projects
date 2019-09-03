//
// Created by adrian on 01.09.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C,
    replace the color of the given pixel and all adjacent same colored pixels with C.

    For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

    B B W
    W W W
    W W W
    B B B
    Becomes

    B B G
    G G G
    G G G
    B B B
 */

#include "day32.h"
#include <stdlib.h>
#include <stdio.h>


void replAdjPix(Color *image, Size *size, Position location, Color c, Color repl)
{
    image[(location.x * size->width) + location.y] = c;

    if(image[((location.x - 1) * size->width) + location.y] == repl) {
        Position pos = {location.x - 1, location.y};
        replAdjPix(image, size, pos, c, repl);
    }
    if(image[(location.x * size->width) + (location.y - 1)] == repl) {
        Position pos = {location.x, location.y - 1};
        replAdjPix(image, size, pos, c, repl);
    }
    if(image[((location.x + 1) * size->width) + location.y] == repl) {
        Position pos = {location.x + 1, location.y};
        replAdjPix(image, size, pos, c, repl);
    }
    if(image[(location.x * size->width) + (location.y + 1)] == repl) {
        Position pos = {location.x, location.y + 1};
        replAdjPix(image, size, pos, c, repl);
    }
    return;
}

