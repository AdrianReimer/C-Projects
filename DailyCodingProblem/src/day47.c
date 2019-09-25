//
// Created by adrianreimer on 9/24/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Airbnb.

    Given a linked list and a positive integer k, rotate the list to the right by k places.

    For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.

    Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.
 */

#include <stdlib.h>
#include "day47.h"


node* rotList(node *root, size_t k)
{
    node *rootPtr = root;
    node *endPtr;
    size_t len = 1;
    while(rootPtr->next != NULL) {
        rootPtr = rootPtr->next;
        len++;
    }
    rootPtr->next = root;
    k = len - (k % len);
    while(k != 0) {
        if (!(k - 1))
            endPtr = root;
        else
            root = root->next;
        k--;
    }
    root = root->next;
    endPtr->next = NULL;
    return root;
}
