#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day62.h"

#define SMALL 5
#define MEDIUM 1000
#define LARGE 100000


int smallList[SMALL] = {4, 3, 0, 1, 5};
int mediumList[MEDIUM];
int largeList[LARGE];

int main()
{
    for(int i = 0; i < MEDIUM; i++) {
        mediumList[i] = i;
    }
    for(int i = 0; i < LARGE; i++) {
        largeList[i] = i;
    }
    assert(hIndex(sizeof(smallList) / sizeof(smallList[0]), smallList) == 3);
    assert(hIndex(sizeof(mediumList) / sizeof(mediumList[0]), mediumList) == MEDIUM / 2);
    assert(hIndex(sizeof(largeList) / sizeof(largeList[0]), largeList) == LARGE / 2);
    return 0;

}