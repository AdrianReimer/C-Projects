#include <stdio.h>
#include <string.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"

static char *A = "abcde";
static char *B = "bcdea";

int main()
{
    printf("%d",isShiftedEquals(A,B));
    return 0;
}