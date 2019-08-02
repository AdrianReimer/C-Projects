#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"


int main()
{
    printf("%s\n",numberRep("10"));
    printf("%s\n",numberRep("-10"));
    printf("%s\n",numberRep("10.1"));
    printf("%s\n",numberRep("-10.1"));
    printf("%s\n",numberRep("1e5"));
    printf("%s\n",numberRep("a"));
    printf("%s\n",numberRep("x 1"));
    printf("%s\n",numberRep("a -2"));
    printf("%s\n",numberRep("-"));
    return 0;
}