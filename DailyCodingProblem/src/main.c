#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"


int main()
{
    char *text1 = readN("text",5);
    char *text2 = readN("text",14);
    printf("%s",text1);
    printf("%s",text2);
    free(text1);
    free(text2);
    return 0;
}