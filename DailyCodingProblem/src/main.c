#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day40.h"


int list1[] = {3, 4, 9, 6, 1};

int main()
{
    int *sol = rightSmallerElements(&list1, sizeof(list1) / sizeof(list1[0]));
    for(int i = 0; i < sizeof(list1) / sizeof(list1[0]); i++)
        printf("%d ", sol[i]);
    return 0;
}