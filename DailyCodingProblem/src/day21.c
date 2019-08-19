//
// Created by adrian on 19.08.2019.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    Find the minimum number of coins required to make n cents.

    You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

    For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
 */

#include "day21.h"

#define NICKEL 5
#define DIME 10
#define QUARTER 25


unsigned int centsToCoins(unsigned int cents)
{
    unsigned int coins = 0;
    unsigned int largestCoinCount;

    largestCoinCount = cents / QUARTER;
    coins += largestCoinCount;
    cents -= largestCoinCount * QUARTER;

    largestCoinCount = cents / DIME;
    coins += largestCoinCount;
    cents -= largestCoinCount * DIME;

    largestCoinCount = cents / NICKEL;
    coins += largestCoinCount;
    cents -= largestCoinCount * NICKEL;

    coins += cents; // rest are Pennies
    return coins;
}