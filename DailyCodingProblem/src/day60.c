//
// Created by adrianreimer on 10/29/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by LinkedIn.

    Given a linked list of numbers and a pivot k,
    partition the linked list so that all nodes
    less than k come before nodes greater than or equal to k.

    For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
    the solution could be 1 -> 0 -> 5 -> 8 -> 3.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day60.h"


void
partitionList(Node *root, int k)
{
    if(root == NULL) {
        fprintf(stderr, "root should not be NULL!");
        return;
    }
    Node *iter = root->next;
    while(iter != NULL) {
        if(iter->data < k ) {
            int tmp = root->data;
            root->data = iter->data;
            iter->data = tmp;
            root = root->next;
        } // Elements < k to the left
        iter = iter->next;
    }
    while(root->next->data != k) {
        root = root->next;
        if(root->next == NULL) {
            fprintf(stderr, "There was no Pivot Element in the List!");
            return;
        }
    } // search for Pivot
    if(root->next->next != NULL) {
        Node *pivot = root->next;
        root->next = root->next->next;
        while(root->next != NULL) {
            root = root->next;
        } // go to last Element
        root->next = pivot;
        pivot->next = NULL;
    } // Add Pivot to the end
}

void
addNode(Node *root, int data)
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    while(root->next != NULL) {
        root = root->next;
    }
    root->next = node;
}

void
freeList(Node *root)
{
    size_t nodeCnt = 0;
    Node *nextNode = root->next;
    while(root != NULL) {
        nodeCnt++;
        free(root);
        root = nextNode;
        if(nextNode != NULL) {
            nextNode = nextNode->next;
        }
    }
}

