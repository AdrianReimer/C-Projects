//
// Created by adrian on 08.09.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Given a string, determine whether any permutation of it is a palindrome.

    For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome.
    daily should return false, since there's no rearrangement that can form a palindrome.
 */

#include "day35.h"
#include <string.h>

#define TRUE 1
#define FALSE 0


int isPalindrome(char *word)
{
    int wordLen = strlen(word);
    char c = 0;
    for(int i = 0; i < wordLen; i++) {
        int charCount = 0;
        for(int j = 0; j < wordLen; j++) {
            if(word[i] == word[j])
                charCount++;
        }
        if(charCount % 2) {
            if(c && c != word[i])
                return FALSE;
            c = word[i];
        }
    }
    return TRUE;
}
