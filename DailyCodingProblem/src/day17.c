//
// Created by adrian on 11.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

    For example, the inorder successor of 22 is 30.

       10
      /  \
     5    30
         /  \
       22    35

    You can assume each node has a parent pointer.
 */

#include "day17.h"
#include <stdlib.h>


Node* inOrderSuccessor(Node *k)
{
    Node *node = k;
    if(k->right != NULL) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    node = k->parent;
    while(node != NULL && node == k->right) {
        k = node;
        node = node->parent;
    }
    return node;
}

Node* insert(Node *node, int data)
{
    if (node == NULL) {
        Node *node = malloc(sizeof(Node));
        node->data   = data;
        node->parent = NULL;
        node->left   = NULL;
        node->right  = NULL;
    }else {
        Node *temp;
        if(data <= node->data) {
            temp = insert(node->left, data);
            node->left  = temp;
            temp->parent= node;
        }else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
        return node;
    }
}