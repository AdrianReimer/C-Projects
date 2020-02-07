#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day64.h"

#define arrLen 6

int arr[arrLen] = {39, 15, 34, 40, 46, 18};


int main()
{
    assert(findPeakElement(arr, arrLen, arrLen / 2) == 46);
    return 0;
}