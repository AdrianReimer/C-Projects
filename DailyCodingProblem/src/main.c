#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day58.h"


int list1[] = {1, 3, 1, 2, 0, 1};
int list2[] = {1, 2, 1, 0, 0};
int list3[] = {2, 2, 1, 5, 0, 0, 0, 0};
int list4[] = {5, 0, 0, 7, 1, 0, 0, 0, 2, 1};
int list5[] = {4, 0, 0, 3, 0, 2, 0, 0, 0, 1};

int main()
{
    assert(canAdvanceToEnd(&list1, sizeof(list1) / sizeof(list1[0])));
    assert(!canAdvanceToEnd(&list2, sizeof(list2) / sizeof(list2[0])));
    assert(canAdvanceToEnd(&list3, sizeof(list3) / sizeof(list3[0])));
    assert(canAdvanceToEnd(&list4, sizeof(list4) / sizeof(list4[0])));
    assert(!canAdvanceToEnd(&list5, sizeof(list5) / sizeof(list5[0])));
}