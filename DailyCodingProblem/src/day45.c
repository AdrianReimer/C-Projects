//
// Created by adrianreimer on 9/23/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    You are given a starting state start, a list of transition probabilities for a Markov chain,
    and a number of steps num_steps. Run the Markov chain starting from start for num_steps and
    compute the number of times we visited each state.

    For example, given the starting state a, number of steps 5000, and the following transition probabilities:

    [
    ('a', 'a', 0.9),
    ('a', 'b', 0.075),
    ('a', 'c', 0.025),
    ('b', 'a', 0.15),
    ('b', 'b', 0.8),
    ('b', 'c', 0.05),
    ('c', 'a', 0.25),
    ('c', 'b', 0.25),
    ('c', 'c', 0.5)
    ]

    One instance of running this Markov chain might produce { 'a': 3012, 'b': 1656, 'c': 332 }.
 */

#include <stdlib.h>
#include <time.h>
#include "day45.h"

#define MAX_RANDOM 1.0


markovEle* markovChain(state startState, size_t steps, transition *list, size_t length)
{
    srand(time(NULL));
    size_t stateCount = 0;
    transition *firstState;
    for(size_t i = 0; i < length; i++) {
        if(list[i].startState == startState) {
            stateCount++;
            if (stateCount == 1)
                firstState = &list[i];
        }
    }

    markovEle *markovChain = malloc(sizeof(markovEle) * stateCount);
    for(size_t i = 0; i < stateCount; i++)
        markovChain[i].state = firstState[i].endState;

    for(size_t i = 0; i < steps; i++) {
        double random = (double)rand() / ((double)RAND_MAX / MAX_RANDOM);
        size_t j = 0;
        while(random > firstState[j].prob) {
            random -= firstState[j].prob;
            j++;
        }
        markovChain[j].count++;
    }
    return markovChain;
}
