#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day54.h"


int list1[] = {-10, -10, 5, 2};
int list2[] = {-10, -2, -2, -2, -1};

int main()
{
    assert(largProd(list1, sizeof(list1) / sizeof(list1[0])) == 500);
    assert(largProd(list2, sizeof(list2) / sizeof(list2[0])) == -4);
}