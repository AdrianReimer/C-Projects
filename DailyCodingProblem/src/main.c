#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day56.h"


int list1[] = {8, -1, 3, 4};
int list2[] = {-4, 5, 1, 0};
int list3[] = {-3, -15, -33, -65, -66, -105};



int main()
{
    assert(maxSubarrSum(&list1, sizeof(list1) / sizeof(list1[0])) == 15);
    assert(maxSubarrSum(&list2, sizeof(list2) / sizeof(list2[0])) == 6);
    assert(maxSubarrSum(&list3, sizeof(list3) / sizeof(list3[0])) == -3);
    assert(maxSubarrSum(NULL, 0) == 0);
}