//
// Created by adrian on 18.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Amazon.

    Implement a bit array.

    A bit array is a space efficient array that holds a value of 1 or 0 at each index.

    init(size): initialize the array with size
    set(i, val): updates index at i with val where val is either 1 or 0.
    get(i): gets the value at index i.
 */

#include "day20.h"
#include <stdlib.h>
#include <stdio.h>


BitArray* init(unsigned int size)
{
    BitArray *bitArr = malloc(sizeof(BitArray));
    bitArr->arr = malloc((size / 8) + 1);
    for(int i = 0; i < size; i++)
        bitArr->arr[i] = 0;
    bitArr->size = --size;
    return(bitArr);
}

void set(BitArray *bitArr, unsigned int i, int val)
{
    if(i > bitArr->size)
        return;
    if(val != 0)
        val = 1;
    bitArr->arr[i / 8] |= val << (i % 8);
}

int get(BitArray *bitArr, unsigned int i)
{
    if(i > bitArr->size)
        return -1;
    int bit = bitArr->arr[i / 8] & (1 << (i % 8));
    return (bit != 0 ? 1 : 0);
}
