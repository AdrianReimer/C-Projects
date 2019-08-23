#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day23.h"


int arr[] = {9, 12, 3, 5, 14, 10, 10};

int main()
{
    changePivot(10,&arr,7);
    for(int i = 0; i < 7; i++)
        printf("%d ",arr[i]);
    return 0;
}