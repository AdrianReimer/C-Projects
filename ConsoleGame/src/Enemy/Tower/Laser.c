//
// Created by adrianreimer on 7/22/19.
//

#include <stdlib.h>
#include "Laser.h"

#define LASER_DELAY 5


static struct Laser upLasers;
static struct Laser rightLasers;
static struct Laser downLasers;
static struct Laser leftLasers;

/* Updates Laser beam positions */
static void updateLasers(Laser* laser, Direction laserDirection)
{
    while(laser != NULL)
    {
        laser->delay++;
        if(laser->delay >= ENEMY_DELAY)
        {
            Position *beamPosition = &laser->beam.pos1;
            for(int i = 0; i < 3; i++)
            {
                setTile(floor, beamPosition);
                switch (laserDirection)
                {
                    case up:
                        beamPosition->posX--;
                        break;
                    case right:
                        beamPosition->posY++;
                        break;
                    case down:
                        beamPosition->posX++;
                        break;
                    case left:
                        beamPosition->posY--;
                        break;
                }
                if(setTile(beam, beamPosition))
                {
                    setTile(floor, beamPosition);
                    beamPosition->posX = laser->beam.rootPos.posX;
                    beamPosition->posY = laser->beam.rootPos.posY;
                    setTile(beam, beamPosition);
                }
                laser->delay -= LASER_DELAY;
                beamPosition++;
            }
        }
        laser = laser->next;
    }
}

void updateLaserBeams()
{
    updateLasers(upLasers.next,up);
    updateLasers(rightLasers.next,right);
    updateLasers(downLasers.next,down);
    updateLasers(leftLasers.next,left);
}

void addLaser(Laser* laser, Direction laserDirection)
{
    Laser* iterator;
    switch (laserDirection)
    {
        case up:
            iterator = &upLasers;
            break;
        case right:
            iterator = &rightLasers;
            break;
        case down:
            iterator = &downLasers;
            break;
        case left:
            iterator = &leftLasers;
            break;
    }
    while(iterator->next != 0)
        iterator = iterator->next;
    iterator->next = laser;
}
