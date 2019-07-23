//
// Created by adrianreimer on 7/22/19.
//

#include <stdlib.h>
#include "Spike.h"
#include "../../World/World.h"

#define SPIKE_DELAY 15


static struct Spike spikes;

/* Updates State of the SpikeTrap */
void updateSpikeTraps()
{
    Spike *spike = spikes.next;
    while(spike != NULL)
    {
        spike->delay++;
        if(spike->delay >= ENEMY_DELAY)
        {
            if(spike->isActive)
            {
                setTile(floor, &spike->pos);
                spike->isActive = 0;
            } else
            {
                setTile(spikeTrap, &spike->pos);
                spike->isActive = 1;
            }
            spike->delay -= SPIKE_DELAY;
        }
        spike = spike->next;
    }
}

void addSpike(Spike* spike)
{
    Spike* iterator = &spikes;
    while(iterator->next != 0)
        iterator = iterator->next;
    iterator->next = spike;
}
