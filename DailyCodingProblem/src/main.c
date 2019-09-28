#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day51.h"

#define MAP_LENGTH 5
#define MAP_WIDTH 6

int map1[] = {1, 0, 0, 0, 0,
               0, 0, 1, 1, 0,
               0, 1, 1, 0, 0,
               0, 0, 0, 0, 0,
               1, 1, 0, 0, 1,
               1, 1, 0, 0, 1};

int map2[] = {1, 0, 0, 0, 1,
              0, 0, 1, 0, 0,
              1, 1, 1, 1, 0,
              0, 0, 0, 0, 0,
              1, 1, 0, 1, 1,
              1, 1, 0, 0, 1};

int main()
{
    assert(islands(MAP_WIDTH, MAP_LENGTH, &map1) == 4);
    assert(islands(MAP_WIDTH, MAP_LENGTH, &map2) == 5);
    return 0;
}