#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day29.h"


int list[] = {1, 2, 3, 4, 5};

int main()
{
    assert(sublistSum(&list, sizeof(list) / sizeof(list[0]), 1, 3) == 5);
    assert(sublistSum(&list, sizeof(list) / sizeof(list[0]), 2, 4) == 7);
    assert(sublistSum(0, sizeof(list) / sizeof(list[0]), 2, 4) == INT_MAX);
    assert(sublistSum(&list, sizeof(list) / sizeof(list[0]), 1, 5) == INT_MAX);
    return 0;
}