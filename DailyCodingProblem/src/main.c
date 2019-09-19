#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day43.h"


char *start = "dog";
char *end = "cat";
char *dic1[] = {"dot", "dop", "dat", "cat"};
char *sol1[] = {"dog", "dot", "dat", "cat"};
char *dic2[] = {"dot", "tod", "dat", "dar"};
char *sol2 = NULL;

int main()
{
    char **seq1 = transformationSeq(start, end, dic1, sizeof(dic1) / sizeof(dic1[0]));
    assert(strcmp(seq1[0], sol1[0]) == 0);
    assert(strcmp(seq1[1], sol1[1]) == 0);
    assert(strcmp(seq1[2], sol1[2]) == 0);
    assert(strcmp(seq1[3], sol1[3]) == 0);
    free(seq1);
    char **seq2 = transformationSeq(start, end, dic2, sizeof(dic2) / sizeof(dic2[0]));
    assert(seq2 == sol2);
    free(seq2);
    return 0;
}