//
// Created by adrianreimer on 10/29/19.
//

#ifndef DAILYCODINGPROBLEM_DAY60_H
#define DAILYCODINGPROBLEM_DAY60_H

typedef struct Node{
    struct Node *next;
    int data;
} Node;

void partitionList(Node *root, int k);
void addNode(Node *root, int data);
void freeList(Node *root);

#endif //DAILYCODINGPROBLEM_DAY60_H
