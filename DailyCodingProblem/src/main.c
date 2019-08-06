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
#include "day13.h"

Node node1;
Node node2;
Node node3;
Node node4;

int main()
{
    node1.data = 9;
    node1.next = &node2;
    node2.data = 9;

    node3.data = 5;
    node3.next = &node4;
    node4.data = 2;

    Node *root = addLists(&node1, &node3);
    while(root) {
        printf("%d -> ", root->data);
        root = root->next;
    }

    return 0;
}