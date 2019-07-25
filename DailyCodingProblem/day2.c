//
// Created by adria on 25.07.2019.
//

/*
 *
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Determine whether a doubly linked list is a palindrome. What if it’s singly linked?

    For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.
 */

#include "day2.h"
#include <stdlib.h>

/*
 * Checks if a double linked List is a Palindrome.
 * @return 1 if list is a Palindrome.
 */
int IsPalindrome(Node *root)
{
    Node *leaf = root;
    while(leaf->child != NULL) {
        leaf = leaf->child;
    }
    while(root->child != NULL) {
        if(root->data != leaf->data)
            return 0;
        root = root->child;
        leaf = leaf->parent;
    }
    return 1;
}
