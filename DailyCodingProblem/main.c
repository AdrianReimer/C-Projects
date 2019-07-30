#include <stdio.h>
#include <string.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"


int main()
{
    int x[] = {-9, -2, 0, 2, 3};
    int length = sizeof(x) / sizeof(x[0]);
    squareSort(&x, length);

    for(int i = 0; i < length; i++)
        printf("%d ",x[i]);

    return 0;
}