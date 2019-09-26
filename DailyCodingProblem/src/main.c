#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day50.h"


int list[] = {2, 4, 3, 8, 7, 5};

int main()
{
    treeNode *root = reconstPOTree(&list, sizeof(list) / sizeof(list[0]));
    return 0;
}