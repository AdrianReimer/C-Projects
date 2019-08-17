//
// Created by adrian on 16.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This question was asked by Apple.

    Given a binary tree, find a minimum path sum from root to a leaf.

    For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

      10
     /  \
    5    5
     \     \
       2    1
           /
         -1
 */

#include "day18.h"
#include <stdlib.h>


int minPathSum(Node *root)
{
    static int absMax = INT_MAX;
    static int currentMax;
    if(root == NULL)
        return 0;
    currentMax += root->data;
    if(root->left == NULL && root->right == NULL && currentMax < absMax)
        absMax = currentMax;
    minPathSum(root->left);
    minPathSum(root->right);
    currentMax -= root->data;
    return absMax;
}

Node* insertNode(Node *node, int data)
{
    if (node == NULL) {
        Node *node = malloc(sizeof(Node));
        node->data   = data;
        node->left   = NULL;
        node->right  = NULL;
    }else {
        Node *temp;
        if(data <= node->data) {
            temp = insertNode(node->left, data);
            node->left  = temp;
        }else {
            temp = insertNode(node->right, data);
            node->right = temp;
        }
        return node;
    }
}


