#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day22.h"


int arr[] = {2, 4, 6, 8, 10, 2, 6, 10};

int main()
{
    printf("%d %d",singlePairAppear(8, arr)[0], singlePairAppear(8, arr)[1]);
    return 0;
}