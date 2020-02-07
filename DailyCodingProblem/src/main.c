#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day65.h"


int main()
{
    assert(boardSolAmt(9) == 5);
    assert(boardSolAmt(0) == 0);
    assert(boardSolAmt(1) == 1);
    assert(boardSolAmt(-1) == 0);
    return 0;
}