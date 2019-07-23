//
// Created by adrianreimer on 7/21/19.
//

#include "Cannon.h"
#include <stdlib.h>

#define CANNON_DELAY 10


static struct Cannon upCannons;
static struct Cannon rightCannons;
static struct Cannon downCannons;
static struct Cannon leftCannons;

/* Updates Cannon projectile position */
static void updateCannons(Cannon* cannon, Direction cannonDirection)
{
    while(cannon != NULL)
    {
        cannon->delay++;
        if(cannon->delay >= ENEMY_DELAY)
        {
            setTile(floor, &cannon->projectilePos);
            switch (cannonDirection)
            {
                case up:
                    cannon->projectilePos.posX--;
                    break;
                case right:
                    cannon->projectilePos.posY++;
                    break;
                case down:
                    cannon->projectilePos.posX++;
                    break;
                case left:
                    cannon->projectilePos.posY--;
                    break;
            }
            if(setTile(projectile, &cannon->projectilePos))
            {
                setTile(floor, &cannon->projectilePos);
                cannon->projectilePos.posX = cannon->projectileRootPos.posX;
                cannon->projectilePos.posY = cannon->projectileRootPos.posY;
                setTile(projectile, &cannon->projectilePos);
            }
            cannon->delay -= CANNON_DELAY;
        }
        cannon = cannon->next;
    }
}

void updateCannonProjectiles()
{
    updateCannons(upCannons.next,up);
    updateCannons(rightCannons.next,right);
    updateCannons(downCannons.next,down);
    updateCannons(leftCannons.next,left);
}

void addCannon(Cannon* cannon, Direction cannonDirection)
{
    Cannon* iterator;
    switch (cannonDirection)
    {
        case up:
            iterator = &upCannons;
            break;
        case right:
            iterator = &rightCannons;
            break;
        case down:
            iterator = &downCannons;
            break;
        case left:
            iterator = &leftCannons;
            break;
    }
    while(iterator->next != 0)
        iterator = iterator->next;
    iterator->next = cannon;
}