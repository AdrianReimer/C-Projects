#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day59.h"


const int list1Sol[] = {1, 1, 3, 3, 2, 0};
const int list2Sol[] = {1, 5, 7, 1, 4};
int list1[] = {1, 3, 3, 2, 0, 1};
int list2[] = {1, 4, 1, 5, 7};

int main()
{
    rotArrRight(&list1, sizeof(list1) / sizeof(list1[0]), 1);
    for(size_t i = 0; i < sizeof(list1) / sizeof(list1[0]); i++) {
        assert(list1[i] == list1Sol[i]);
    }
    rotArrRight(&list2, sizeof(list2) / sizeof(list2[0]), 3);
    for(size_t i = 0; i < sizeof(list2) / sizeof(list2[0]); i++) {
        assert(list2[i] == list2Sol[i]);
    }
}