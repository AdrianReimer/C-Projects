#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day46.h"


char *s1 = "abc";
char *s2 = "bcd";
char *s3 = "foo";
char *s4 = "bar";

int main()
{
    assert(isOneToOneRel(s1,s2));
    assert(isOneToOneRel(s2,s1));
    assert(!isOneToOneRel(s3,s4));
    assert(!isOneToOneRel(s4,s3));
    assert(!isOneToOneRel(s1,s3));
    return 0;
}