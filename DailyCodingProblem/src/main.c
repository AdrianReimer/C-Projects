#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day48.h"


int main()
{
    assert(foo((Node){{10, 5}, 1}) == 5);
    assert(foo((Node){{10, 5}, 0}) == 10);
    return 0;
}