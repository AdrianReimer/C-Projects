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
#include "day17.h"


int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 22);
    root = insert(root, 35);
    assert(inOrderSuccessor(root->right->left)->data == 30);
    return 0;
}