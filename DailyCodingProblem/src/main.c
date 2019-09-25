#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day47.h"


node ele3 = {5, NULL};
node ele2 = {3, &ele3};
node ele1 = {7, &ele2};
node root = {7, &ele1};

int main()
{
    node *root2r = rotList(&root, 2);
    assert(root2r->num == 3);
    assert(root2r->next->num == 5);
    assert(root2r->next->next->num == 7);
    assert(root2r->next->next->next->num == 7);
    assert(root2r->next->next->next->next == 0);
    return 0;
}