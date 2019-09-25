//
// Created by adrianreimer on 9/24/19.
//

#ifndef DAILYCODINGPROBLEM_DAY47_H
#define DAILYCODINGPROBLEM_DAY47_H

typedef struct node {
    int num;
    struct node *next;
} node;

node* rotList(node *root, size_t k);

#endif //DAILYCODINGPROBLEM_DAY47_H
