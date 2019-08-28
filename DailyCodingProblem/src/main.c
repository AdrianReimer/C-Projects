#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day30.h"


int list1[] = {10, 5, 7};
int list2[] = {10, 5, 1};

int main()
{
    assert(isIncreasingOrder(&list1, sizeof(list1) / sizeof(list1[0])));
    assert(!isIncreasingOrder(&list2, sizeof(list2) / sizeof(list2[0])));
    return 0;
}