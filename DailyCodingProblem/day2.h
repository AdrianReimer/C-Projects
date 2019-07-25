//
// Created by adria on 25.07.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY2_H
#define DAILYCODINGPROBLEM_DAY2_H

typedef struct Node {
    int data;
    struct node *parent;
    struct node *child;
} Node;

int IsPalindrome(Node *root);

#endif //DAILYCODINGPROBLEM_DAY2_H
