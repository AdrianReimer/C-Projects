//
// Created by adrianreimer on 7/22/19.
//

#ifndef CONSOLEGAME_SPIKE_H
#define CONSOLEGAME_SPIKE_H

#include "../../World/World.h"


typedef struct Spike
{
    unsigned int delay;
    unsigned int isActive;
    Position pos;
    struct Spike* next;
} Spike;

void updateSpikeTraps();
void addSpike(Spike* spike);

#endif //CONSOLEGAME_SPIKE_H
