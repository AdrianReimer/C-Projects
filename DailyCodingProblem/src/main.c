#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day57.h"


Interval intervals1[] = {{7, 9}, {2, 4}, {5, 8}};
Interval intervals2[] = {{7, 9}, {2, 4}, {5, 8}, {3, 7}};
Interval intervals3[] = {{7, 9}, {2, 4}, {5, 8}, {3, 7}, {8, 11}, {1, 2}};
Interval intervals4[] = {{15, 30}, {16, 19}, {17, 32}, {30, 35}, {1, 3}, {3, 5}};

int main()
{
    assert(minOverlap(&intervals1, sizeof(intervals1) / sizeof(intervals1[0])) == 1);
    assert(minOverlap(&intervals2, sizeof(intervals2) / sizeof(intervals2[0])) == 2);
    assert(minOverlap(&intervals3, sizeof(intervals3) / sizeof(intervals3[0])) == 3);
    assert(minOverlap(&intervals4, sizeof(intervals4) / sizeof(intervals4[0])) == 2);
    assert(minOverlap(NULL, 0) == 0);
}