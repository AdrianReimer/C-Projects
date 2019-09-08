#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day36.h"


char *text1 = "acbbac";
char *text2 = "abcdef";

int main()
{
    assert(recurChar(text1) == 'b');
    assert(recurChar(text2) == NULL);
    return 0;
}