#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day33.h"


int numbers[] = {1, 2, 3, 4};
float probs[] = {0.1, 0.5, 0.2, 0.2};

int main()
{
    for(int i = 0; i <  100; i++)
        printf("%d\n", genRndNum(&numbers, &probs, sizeof(numbers) / sizeof(numbers[0])));
    return 0;
}