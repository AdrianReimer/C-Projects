//
// Created by adrianreimer on 9/26/19.
//

#ifndef DAILYCODINGPROBLEM_DAY50_H
#define DAILYCODINGPROBLEM_DAY50_H

typedef struct treeNode {
    int number;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* reconstPOTree(int *list, size_t len);

#endif //DAILYCODINGPROBLEM_DAY50_H
