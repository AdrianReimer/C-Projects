#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"

int list[6] = {5, 1, 2, 3, 4, 5};

int main()
{
    int *sol = contiguousSum(list, 12);
    free(sol);
    return 0;
}