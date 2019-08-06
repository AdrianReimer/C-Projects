//
// Created by adrian on 06.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY13_H
#define DAILYCODINGPROBLEM_DAY13_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* addLists(Node *root1, Node *root2);

#endif //DAILYCODINGPROBLEM_DAY13_H
