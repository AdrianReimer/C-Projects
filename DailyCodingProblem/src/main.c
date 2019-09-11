#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day39.h"


int list1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2};
int list2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 5, 12, 13};
int list3[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int main()
{
    assert(findDuplicate(&list1, sizeof(list1) / sizeof(list1[0])) == 2);
    assert(findDuplicate(&list2, sizeof(list2) / sizeof(list2[0])) == 5);
    assert(findDuplicate(&list3, sizeof(list3) / sizeof(list3[0])) == 1);
    return 0;
}