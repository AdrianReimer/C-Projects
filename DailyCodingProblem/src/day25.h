//
// Created by adrian on 24.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY25_H
#define DAILYCODINGPROBLEM_DAY25_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addNode(Node *root, int data);
void printList(Node *root);
void swapPairs(Node *root);

#endif //DAILYCODINGPROBLEM_DAY25_H
