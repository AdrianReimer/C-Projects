#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day24.h"


int arr[] = {4, 1, 3, 5, 6};
int arr2[] = {9, 5, 14, 1, 54, -2, 7};

int main()
{
    assert(nearestLargerNumber(0,&arr,sizeof(arr) / sizeof(arr[0])) == 3);
    assert(nearestLargerNumber(1,&arr,sizeof(arr) / sizeof(arr[0])) == 0);
    assert(nearestLargerNumber(0,&arr2,sizeof(arr2) / sizeof(arr2[0])) == 2);
    assert(nearestLargerNumber(4,&arr2,sizeof(arr2) / sizeof(arr2[0])) == -1);
    return 0;
}