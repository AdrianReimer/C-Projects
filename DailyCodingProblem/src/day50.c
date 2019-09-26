//
// Created by adrianreimer on 9/26/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

    For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

        5
       / \
      3   7
     / \   \
    2   4   8
 */

#include <stdlib.h>
#include "day50.h"


void addNode(treeNode *root, treeNode* ele)
{
    if(root->number > ele->number) {
        if(root->left == NULL) {
            root->left = ele;
        }
        addNode(root->left, ele);
    } else if(root->number < ele->number) {
        if(root->right == NULL) {
            root->right = ele;
        }
        addNode(root->right, ele);
    }
}

treeNode* reconstPOTree(int *list, size_t len)
{
    treeNode *treeNodeList = malloc(sizeof(treeNode) * len);
    treeNodeList[0].number = list[len - 1];
    for(size_t i = 1; i < len; i++) {
        treeNodeList[i].number = list[len - i - 1];
        addNode(&treeNodeList[0], &treeNodeList[i]);
    }
    return &treeNodeList[0];
}
