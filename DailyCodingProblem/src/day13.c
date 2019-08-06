//
// Created by adrian on 06.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Microsoft.

    Let's represent an integer in a linked list format by having each node represent a digit in the number.
    The nodes make up the number in reversed order.

    For example, the following linked list:

    1 -> 2 -> 3 -> 4 -> 5
    is the number 54321.

    Given two linked lists in this format, return their sum in the same linked list format.

    For example, given

    9 -> 9
    5 -> 2
    return 124 (99 + 25) as:

    4 -> 2 -> 1
 */

#include "day13.h"
#include <stdlib.h>

#define BASE10 10

Node* addLists(Node *root1, Node *root2)
{
    // 2,147,483,647 + '\0' = 11 characters
    char *text1 = "          ";
    char *text2 = "          ";
    text1 += 10;
    text2 += 10;

    for(int i = 10; root1 != NULL; i--) {
        *--text1 = root1->data + '0';
        root1 = root1->next;
    }
    for(int i = 10; root2 != NULL; i--) {
        *--text2 = root2->data + '0';
        root2 = root2->next;
    }

    int number1 = atoi(text1);
    int number2 = atoi(text2);
    int sum = number1 + number2;

    char sumText[11] = "          ";
    _itoa_s(sum, &sumText, 10, BASE10);

    Node *root = malloc(sizeof(Node));
    Node *rootptr = root;
    for(int i = 10; i >= 0; i--) {
        if(sumText[i] >= '0' && sumText[i] <= '9') {
            Node *node = malloc(sizeof(Node));
            node->data = sumText[i] - '0';
            root->next = node;
            root = node;
        }
    }
    return rootptr->next;
}
