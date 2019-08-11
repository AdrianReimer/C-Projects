//
// Created by adrian on 11.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY17_H
#define DAILYCODINGPROBLEM_DAY17_H

typedef struct Node
{
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

Node* inOrderSuccessor(Node *k);
Node* insert(Node* node, int data);

#endif //DAILYCODINGPROBLEM_DAY17_H
