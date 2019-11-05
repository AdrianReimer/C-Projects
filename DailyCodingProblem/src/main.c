#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day61.h"


static ConnectFourGame game = {P1};

int main()
{
    connectFourTestDiagonal();
    connectFourTestHorizontal();
    connectFourTestVertical();
    return 0;
}