#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day34.h"


int numbers[] = {1, 2, 1, 1, 3, 4, 0};

int main()
{
    assert(majorityElement(&numbers, sizeof(numbers) / sizeof(numbers[0])) == 1);
    return 0;
}