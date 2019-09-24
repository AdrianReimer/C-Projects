#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "day45.h"


transition list[] = {{a, a, 0.9},
                     {a, b, 0.075},
                     {a, c, 0.025},
                     {b, a, 0.15},
                     {b, b, 0.8},
                     {b, c, 0.05},
                     {c, a, 0.25},
                     {c, b, 0.25},
                     {c, c, 0.5}};

int main()
{
    markovEle *sol = markovChain(a, 5000, &list, sizeof(list) / sizeof(list[0]));
    for(size_t i = 0; i < 3; i++)
        printf("%c : %d\n", sol[i].state, sol[i].count);
    return 0;
}