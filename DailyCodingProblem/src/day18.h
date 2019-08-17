//
// Created by adrian on 16.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY18_H
#define DAILYCODINGPROBLEM_DAY18_H

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int minPathSum(Node *root);
Node* insertNode(Node *node, int data);

#endif //DAILYCODINGPROBLEM_DAY18_H
