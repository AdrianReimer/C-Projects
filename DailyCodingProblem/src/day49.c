//
// Created by adrianreimer on 9/26/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Two Sigma.

    Alice wants to join her school's Probability Student Club.
    Membership dues are computed via one of two simple probabilistic games.

    The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six.
    Your number of rolls is the amount you pay, in dollars.

    The second game: same, except that the stopping condition is a five followed by a five.

    Which of the two games should Alice elect to play? Does it even matter?
    Write a program to simulate the two games and calculate their expected value.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "day49.h"

#define ROLL_DICE (rand() % 6 + 1)


static size_t gameA()
{
    size_t money = 0;
    while(1) {
        while(ROLL_DICE != 5)
            money++;
        money++;
        if(ROLL_DICE == 6)
            return ++money;
    }
}

static size_t gameB()
{
    size_t money = 0;
    while(1) {
        while(ROLL_DICE != 5)
            money++;
        money++;
        if(ROLL_DICE == 5)
            return ++money;
    }
}

void printGameStats(size_t gameRounds)
{
    srand(time(NULL));
    size_t gameAMoney = 0;
    size_t gameBMoney = 0;
    for(size_t i = 0; i < gameRounds; i++) {
        gameAMoney+= gameA();
        gameBMoney+= gameB();
    }
    printf("Mean Money loss on Game A: %d\n",gameAMoney/gameRounds);
    printf("Mean Money loss on Game B: %d\n",gameBMoney/gameRounds);
}