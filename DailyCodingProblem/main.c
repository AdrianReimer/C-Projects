#include <stdio.h>
#include <string.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"


int main()
{
    Interval intervalList[] = {{0, 3}, {2, 6}, {3, 4}, {6, 9}};
    int length = sizeof(intervalList) / sizeof(intervalList[0]);
    Interval *interval = smallestInterval(&intervalList, length);

    printf("{%d, %d}",interval->from, interval->to);

    return 0;
}