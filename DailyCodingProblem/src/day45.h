//
// Created by adrianreimer on 9/23/19.
//

#ifndef DAILYCODINGPROBLEM_DAY45_H
#define DAILYCODINGPROBLEM_DAY45_H

#include <glob.h>


typedef enum state {
    a = 97, b, c, d, e, f, g
} state;

typedef struct transition {
    state startState;
    state endState;
    double prob;
} transition;

typedef struct markovEle {
    state state;
    size_t count;
} markovEle;

markovEle* markovChain(state startState, size_t steps, transition *list, size_t length);

#endif //DAILYCODINGPROBLEM_DAY45_H
