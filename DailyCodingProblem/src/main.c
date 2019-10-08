#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day55.h"


Rectangle rectList1[] = {{{1, 4}, {3, 3}},
                        {{-1, 3}, {2, 1}},
                        {{0, 5}, {4, 3}}};

Rectangle rectList2[] = {{{1, 4}, {3, 7}},
                        {{-1, 3}, {2, 1}},
                        {{0, 5}, {4, 3}}};

int main()
{
    assert(isOverlappingRect(&rectList1, sizeof(rectList1) / sizeof(rectList1[0])));
    assert(!isOverlappingRect(&rectList2, sizeof(rectList2) / sizeof(rectList2[0])));
    assert(!isOverlappingRect(NULL, 5));
}