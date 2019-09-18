#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day42.h"


timestamp root = {NULL, 1526579928, 3, Enter};
timestamp data1 = {NULL, 1526579929, 4, Enter};
timestamp data2 = {NULL, 1526579930, 2, Exit};
timestamp data3 = {NULL, 1526579931, 1, Exit};
timestamp data4 = {NULL, 1526579932, 4, Exit};

int main()
{
    addTimestamp(&root, &data1);
    addTimestamp(&root, &data2);
    addTimestamp(&root, &data3);
    addTimestamp(&root, &data4);
    time_t *busiestTime = busiestPeriod(&root);
    assert(busiestTime[0] == 1526579929 && busiestTime[1] == 1526579930);
    return 0;
}