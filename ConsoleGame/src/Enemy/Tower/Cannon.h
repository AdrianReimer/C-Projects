//
// Created by adrianreimer on 7/21/19.
//

#ifndef CONSOLEGAME_CANNON_H
#define CONSOLEGAME_CANNON_H

#include "../../World/World.h"


typedef struct Cannon
{
    unsigned int delay;
    Position projectilePos;
    Position projectileRootPos;
    struct Cannon* next;
} Cannon;

void updateCannonProjectiles();
void addCannon(Cannon* cannon, Direction cannonDirection);


#endif //CONSOLEGAME_CANNON_H
