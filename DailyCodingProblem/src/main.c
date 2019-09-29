#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day52.h"


int main()
{
    assert(perfNum(10) == 910);
    assert(perfNum(11) == 811);
    assert(perfNum(0) == 19);
    assert(perfNum(555) == 55);
    assert(perfNum(123115) == 3115);
    assert(perfNum(131115) == 21115);
    return 0;
}