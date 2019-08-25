#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day26.h"


int main()
{
    assert(divide(9,3) == 3);
    assert(divide(10,3) == 3);
    assert(divide(16,2) == 8);
    assert(divide(15,5) == 3);
    assert(divide(1000,10) == 100);
    return 0;
}