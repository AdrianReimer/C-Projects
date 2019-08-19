#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day21.h"


int main()
{
    assert(centsToCoins(16) == 3);
    assert(centsToCoins(10) == 1);
    assert(centsToCoins(25) == 1);
    assert(centsToCoins(12) == 3);
    assert(centsToCoins(15) == 2);
    assert(centsToCoins(100) == 4);
    return 0;
}