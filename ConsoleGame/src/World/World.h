//
// Created by adrianreimer on 7/21/19.
//

#ifndef CONSOLEGAME_WORLD_H
#define CONSOLEGAME_WORLD_H

#define WORLD_SPACE 64
#define RANDOM_SHOOT (rand() % 80)
#define ENEMY_DELAY 100


typedef struct Position
{
    int posX;
    int posY;
} Position;

typedef enum Tile
{
    wall = 'X',
    floor = ' ',
    myplayer = 'P',
    myend = 'E',
    cannonTower = 'C',
    projectile = 'o',
    laserTower = 'L',
    beam = '+',
    spikeTrap = '#'
} Tile;

typedef enum Towers
{
    cannonUp = '0',
    cannonRight = '1',
    cannonDown = '2',
    cannonLeft = '3',
    laserUp = '4',
    laserRight = '5',
    laserDown = '6',
    laserLeft = '7',
};

typedef enum Direction
{
    up,right,down,left
} Direction;

void createWorld();
void DrawWorld();
int setTile(Tile, Position*);
Tile getTile(Position *position);


#endif //CONSOLEGAME_WORLD_H
