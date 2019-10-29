#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "day60.h"


const int sol1[] = {1, 0, 8, 5, 3};

int main()
{
    Node *root = malloc(sizeof(Node));
    root->data = 5;
    addNode(root, 1);
    addNode(root, 8);
    addNode(root, 0);
    addNode(root, 3);
    partitionList(root, 3);

    Node *iter = root;
    for(size_t i = 0; i < sizeof(sol1) / sizeof(sol1[0]); i++) {
        assert(iter->data == sol1[i]);
        iter = iter->next;
    }
    freeList(root);
}