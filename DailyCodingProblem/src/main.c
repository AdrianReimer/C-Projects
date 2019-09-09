#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "day37.h"


int main()
{
    assert(reverseBits(0b11110000111100001111000011110000)
                    == 0b00001111000011110000111100001111);
    assert(reverseBits(0b11010000111100101111000010010000)
                    == 0b00101111000011010000111101101111);
    return 0;
}