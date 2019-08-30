//
// Created by adrian on 30.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by LinkedIn.

    Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

    For example, given the list of points [(0, 0), (5, 4), (3, 1)],
    the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
 */

#include "day31.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


Point* nearestPoints(Point *list, unsigned int length, Point *center, int k)
{
    if(list == NULL || center == NULL || k > length)
        return NULL;

    Point *nearestPoints = malloc(sizeof(Point) * k);
    for(int i = 0; i < k; i++)
        nearestPoints[i] = list[i];

    for(int i = k; i < length; i++) {
        unsigned int dist = sqrt(pow(list[i].x, 2) + pow(list[i].y, 2));
        unsigned int maxDist = sqrt(pow(nearestPoints[0].x, 2) + pow(nearestPoints[0].y, 2));
        unsigned int maxIdx = 0;
        for(int n = 1; n < k; n++) {
            unsigned int curDist = sqrt(pow(nearestPoints[n].x, 2) + pow(nearestPoints[n].y, 2));
            if(curDist > maxDist) {
                maxDist = curDist;
                maxIdx = n;
            }
        }
        if(dist < maxDist)
            nearestPoints[maxIdx] = list[i];

    }
    return nearestPoints;
}