//
// Created by adrianreimer on 7/22/19.
//

#ifndef CONSOLEGAME_LASER_H
#define CONSOLEGAME_LASER_H

#include "../../World/World.h"


typedef struct Beam
{
    Position rootPos;
    Position pos1;
    Position pos2;
    Position pos3;
} Beam;

typedef struct Laser
{
    unsigned int delay;
    Beam beam;
    struct Laser* next;
} Laser;

void updateLaserBeams();
void addLaser(Laser* laser, Direction laserDirection);

#endif //CONSOLEGAME_LASER_H
