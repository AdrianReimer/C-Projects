#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day28.h"


int main()
{
    int *list = generateGrayCode(2);
    assert(list[2] == 0b11);
    free(list);
    list = generateGrayCode(3);
    assert(list[4] == 0b110);
    free(list);
    return 0;
}