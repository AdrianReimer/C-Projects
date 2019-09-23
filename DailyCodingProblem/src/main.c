#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day44.h"


char *start = "hello";
char *end = "world";
char *text1 = "hello world dog cat hello cat dog dog hello cat world";
char *text2 = "hello this is a text world dog cat hello";
char *text3 = "In thishello sentence there is noworld start or stop word";

int main()
{
    assert(smallestDist(start, end, text1) == 0);
    assert(smallestDist(start, end, text2) == 4);
    assert(smallestDist(start, end, NULL) == INT_MAX);
    assert(smallestDist(start, end, text3) == INT_MAX);
    return 0;
}