//
// Created by adrian on 04.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY11_H
#define DAILYCODINGPROBLEM_DAY11_H

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

typedef struct treeNodePair {
    treeNode *first;
    treeNode *second;
} treeNodePair;

treeNodePair nodePairSum(treeNode *root, int k);

#endif //DAILYCODINGPROBLEM_DAY11_H
