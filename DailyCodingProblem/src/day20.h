//
// Created by adrian on 18.08.2019.
//

#ifndef DAILYCODINGPROBLEM_DAY20_H
#define DAILYCODINGPROBLEM_DAY20_H

typedef struct BitArray {
    unsigned char *arr;
    unsigned int size;
} BitArray;

BitArray* init(unsigned int size);
void set(BitArray *bitArr, unsigned int i, int val);
int get(BitArray *bitArr, unsigned int i);

#endif //DAILYCODINGPROBLEM_DAY20_H
