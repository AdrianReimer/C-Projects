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

treeNode node1;
treeNode node2;
treeNode node3;
treeNode node4;
treeNode node5;

int main()
{
    node1.data = 10;
    node1.left = &node2;
    node1.right = &node3;
    node2.data = 5;
    node3.data = 15;
    node3.left = &node4;
    node3.right = &node5;
    node4.data = 11;
    node5.data = 15;
    treeNodePair pair = nodePairSum(&node1,26);
    printf("%d %d",pair.first->data,pair.second->data);
    return 0;
}