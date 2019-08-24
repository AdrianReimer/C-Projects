//
// Created by adrian on 24.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given the head of a singly linked list, swap every two nodes and return its head.

    For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day25.h"


void addNode(Node *root, int data)
{
    while(root->next != NULL)
        root = root->next;
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    root->next = node;
}

void printList(Node *root)
{
    while(root != NULL) {
        if(root ->next == NULL)
            printf("%d",root->data);
        else
            printf("%d -> ",root->data);
        root = root->next;
    }
}

void swapPairs(Node *root)
{
    int isEvenElement = 1;
    int *last;
    while(root != NULL) {
        if(isEvenElement) {
            isEvenElement = 0;
            last = &root->data;
        } else {
            int temp = root->data;
            root->data = *last;
            *last = temp;
            isEvenElement++;
        }
        root = root->next;
    }
}
