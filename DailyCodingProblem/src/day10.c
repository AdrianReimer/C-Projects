//
// Created by adrian on 03.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Cisco.

    Given an unsigned 8-bit integer, swap its even and odd bits.
    The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.

    For example, 10101010 should be 01010101. 11100010 should be 11010001.

    Bonus: Can you do this in one line?
 */

#include "day10.h"

#define ODD_MASK  0b01010101
#define EVEN_MASK 0b10101010

unsigned char swapChar(char c)
{
    return ((c >> 1) & ODD_MASK) | ((c << 1) & EVEN_MASK);
}


