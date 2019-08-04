//
// Created by adrian on 04.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Given the root of a binary search tree, and a target K,
    return two nodes in the tree whose sum equals K.

    For example, given the following tree and K of 20

        10
       /   \
     5      15
           /  \
         11    15
    Return the nodes 5 and 15.
 */

#include "day11.h"
#include <stdlib.h>
#include <stdio.h>

treeNodePair nodePairSum(treeNode *root, int k)
{
    if(root->left == NULL && root->right == NULL) {
        treeNodePair pair = {0,0};
        return pair;
    }
    int sum = root->data;
    if (root->left != NULL) {
        if ((sum += root->left->data) == k) {
            treeNodePair pair = {root, root->left};
            return pair;
        }
    }
    sum -= root->left->data;
    if (root->right != NULL) {
        if ((sum += root->right->data) == k) {
            treeNodePair pair = {root, root->right};
            return pair;
        }
    }
    treeNodePair pair = nodePairSum(root->left, k);
    if(pair.first == NULL)
        pair = nodePairSum(root->right, k);
    return pair;
}


