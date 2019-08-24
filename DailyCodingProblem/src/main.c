#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day25.h"

Node root = {1, NULL};

int main()
{
    addNode(&root, 2);
    addNode(&root, 3);
    addNode(&root, 4);
    swapPairs(&root);
    printList(&root);
    return 0;
}