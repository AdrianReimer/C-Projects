//
// Created by adrianreimer on 2/7/20.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Wayfair.

    You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

    Dominoes, or 2 x 1 rectangles.
    Trominoes, or L-shapes.

    For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

    A B B C
    A B C C

    Given an integer N, determine in how many ways this task is possible.
 */

#include "day65.h"

int64_t
boardSolAmt(int64_t N)
{
    if(N <= 0) {
        return 0;
    }
    int64_t solCnt = 1; // filled with dominoes
    int64_t tromCnt = 0;
    while((N-=3) >= 0) {
        solCnt++; // step by step stuffed with 2 trominoes
        tromCnt++;
    }
    if(tromCnt >= 3) {
        solCnt += tromCnt - 2; // flipping of board considered (1101 <=> 1011)
    }
    return solCnt;
}
