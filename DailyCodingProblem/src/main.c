#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day31.h"


Point points[3] = {{0, 0}, {5, 4}, {3, 1}};
Point center = {1, 2};

int main()
{
    Point *nearPoints = nearestPoints(&points, sizeof(points) / sizeof(points[0]), &center, 2);
    for(int i = 0; i < 2; i++)
        printf("%d %d \n", nearPoints[i].x, nearPoints[i].y);
    return 0;
}