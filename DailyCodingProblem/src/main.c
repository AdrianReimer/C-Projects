#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"

int arr[] = {1, 2, 3, 4, 5, 6};

int main()
{
    int length = sizeof(arr) / sizeof(arr[0]);
    rotateList(&arr, length, 2);
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}