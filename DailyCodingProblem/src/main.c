#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include "day1.h"
//#include "day2.h"
//#include "day3.h"
//#include "day4.h"
//#include "day5.h"
//#include "day6.h"
//#include "day7.h"
//#include "day8.h"
//#include "day9.h"
//#include "day10.h"
//#include "day11.h"
//#include "day12.h"
//#include "day13.h"
//#include "day14.h"
//#include "day15.h"
//#include "day16.h"
//#include "day17.h"
//#include "day18.h"
#include "day19.h"

const int array[4][4] = {{1, 0, 0, 0},
                        {1, 0, 1, 1},
                        {1, 0, 1, 1},
                        {0, 1, 0, 0}};


int main()
{
    largestRectangle(4, 4, array);
    return 0;
}