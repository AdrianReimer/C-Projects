#include <stdio.h>
#include <string.h>
#include "day1.h"
#include "day2.h"

Node root;
Node ele1;
Node ele2;
Node ele3;
Node ele4;

int main() {
    root.data = 1;
    ele1.data = 4;
    ele2.data = 3;
    ele3.data = 4;
    ele4.data = 1;
    root.child = &ele1;
    ele1.parent = &root;
    ele1.child = &ele2;
    ele2.parent = &ele1;
    ele2.child = &ele3;
    ele3.parent = &ele2;
    ele3.child = &ele4;
    ele4.parent = &ele3;
    printf("%d",IsPalindrome(&root));
    return 0;
}