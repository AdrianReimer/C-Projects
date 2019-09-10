#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day38.h"


char expression1[] = {'5', '3', '+'};
char expression2[] = {'1', '7', '1', '1', '+', '-', '/', '3', '*', '2', '1', '1', '+', '+', '-'};
char expression3[] = {'1', '+', '1', '+'};
char expression4[] = {'1', '+', '1', '-', '1', '1', '*', '*'};

int main()
{
    assert(revPolNot(&expression1, sizeof(expression1) / sizeof(expression1[0])) == 8);
    assert(revPolNot(&expression2, sizeof(expression2) / sizeof(expression2[0])) == -4);
    assert(revPolNot(&expression3, sizeof(expression3) / sizeof(expression3[0])) == 2);
    assert(revPolNot(&expression4, sizeof(expression4) / sizeof(expression4[0])) == 0);
    return 0;
}