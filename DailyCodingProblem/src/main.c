#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include "day1.h"
//#include "day2.h"
//#include "day3.h"
//#include "day4.h"
//#include "day5.h"
//#include "day6.h"
//#include "day7.h"
//#include "day8.h"
//#include "day9.h"
//#include "day10.h"
//#include "day11.h"
//#include "day12.h"
//#include "day13.h"
//#include "day14.h"
//#include "day15.h"
//#include "day16.h"
//#include "day17.h"
#include "day18.h"


int main()
{
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 30);
    root = insertNode(root, 22);
    root = insertNode(root, 35);
    printf("%d",minPathSum(root));
    return 0;
}