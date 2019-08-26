#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day27.h"

char *text1 = ")(";
char *text2 = "()())()";
char *text3 = "()()))(()";
char *text4 = "This) Text has ( two ) wrong Parentheses (";

int main()
{
    assert(parenthesesCheck(text1) == 2);
    assert(parenthesesCheck(text2) == 1);
    assert(parenthesesCheck(text3) == 3);
    assert(parenthesesCheck(text4) == 2);
    return 0;
}