//
// Created by adrian on 08.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Facebook.

    Given an array of numbers representing the stock prices of a company in chronological order and an integer k,
    return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it,
    and you must sell the stock before you can buy it again.

    For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
 */

#include <stdlib.h>
#include <stdio.h>
#include "day15.h"


int maxProfit(int *list, int k)
{
    int max = 0;
    if(list == NULL || *list <= 0 || k <= 0)
        return 0;
    int length = list[0];
    if(length > 1) {
        int stock = 0;
        for(int i = 1; i < length; i++) {
            if(stock && ((list[i + 1] - stock) > ((list[i] - stock)))) {
                continue;
            }
            else {
                if(stock && (k > 0) && (list[i] > stock )) {
                    max += list[i] - stock;
                    stock = 0;
                    k--;
                }
                if(list[i] < list[i + 1])
                    stock = list[i];
            }
        }
    }
    return max;
}
