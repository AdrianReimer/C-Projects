#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day35.h"


char *word1 = "carrace";
char *word2 = "daily";
char *word3 = "alula";
char *word4 = "anna";
char *word5 = "ana";
char *word6 = "anaa";
char *word7 = "bxaanbaax";

int main()
{
    assert(isPalindrome(word1));
    assert(!isPalindrome(word2));
    assert(isPalindrome(word3));
    assert(isPalindrome(word4));
    assert(isPalindrome(word5));
    assert(!isPalindrome(word6));
    assert(isPalindrome(word7));
    return 0;
}