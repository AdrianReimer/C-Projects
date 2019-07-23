//
// Created by adrianreimer on 7/21/19.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "World.h"
#include "../Enemy/Tower/Cannon.h"
#include "../Enemy/Tower/Laser.h"
#include "../Enemy/Trap/Spike.h"
#include "../Player/Player.h"

#define PLAYER_MOVE_DELAY 128
#define THIRTY_MS 30000
#define MAP_PATH "res/mymap1"
#define PLAYER_MOVE1 "\nMake your first Turn [W,A,S,D]: "
#define PLAYER_MOVE2 "\nMake your second Turn [W,A,S,D]: "
#define WIN "You Won!\n"
#define LOSE "You Lost!\n"


Tile world[WORLD_SPACE][WORLD_SPACE];

/* Creates a Cannon with a fix shoot direction.
 * Adds created Cannon to the related Linked List.*/
static inline void CreateCannons(char c, int x, int y)
{
    Cannon *cannon = malloc(sizeof(struct Cannon));
    cannon->delay = RANDOM_SHOOT;
    switch (c) {
        case cannonUp:
            cannon->projectilePos.posX = x - 1;
            cannon->projectilePos.posY = y;
            cannon->projectileRootPos.posX = x - 1;
            cannon->projectileRootPos.posY = y;
            addCannon(cannon, up);
            break;
        case cannonRight:
            cannon->projectilePos.posX = x;
            cannon->projectilePos.posY = y + 1;
            cannon->projectileRootPos.posX = x;
            cannon->projectileRootPos.posY = y + 1;
            addCannon(cannon, right);
            break;
        case cannonDown:
            cannon->projectilePos.posX = x + 1;
            cannon->projectilePos.posY = y;
            cannon->projectileRootPos.posX = x + 1;
            cannon->projectileRootPos.posY = y;
            addCannon(cannon, down);
            break;
        case cannonLeft:
            cannon->projectilePos.posX = x;
            cannon->projectilePos.posY = y - 1;
            cannon->projectileRootPos.posX = x;
            cannon->projectileRootPos.posY = y - 1;
            addCannon(cannon, left);
            break;
    }
    world[x][y] = cannonTower;
}

/* Creates a Laser with a fix shoot direction.
 * Adds created Laser to the related Linked List.*/
static inline void CreateLasers(char c, int x, int y)
{
    Laser *laser = malloc(sizeof(struct Laser));
    laser->delay = RANDOM_SHOOT;
    switch (c)
    {
        case laserUp:
            laser->beam.pos1.posX = x - 3;
            laser->beam.pos1.posY = y;
            laser->beam.pos2.posX = x - 2;
            laser->beam.pos2.posY = y;
            laser->beam.pos3.posX = x - 1;
            laser->beam.pos3.posY = y;
            laser->beam.rootPos.posX = x - 1;
            laser->beam.rootPos.posY = y;
            addLaser(laser,up);
            break;
        case laserRight:
            laser->beam.pos1.posX = x;
            laser->beam.pos1.posY = y + 3;
            laser->beam.pos2.posX = x;
            laser->beam.pos2.posY = y + 2;
            laser->beam.pos3.posX = x;
            laser->beam.pos3.posY = y + 1;
            laser->beam.rootPos.posX = x;
            laser->beam.rootPos.posY = y + 1;
            addLaser(laser,right);
            break;
        case laserDown:
            laser->beam.pos1.posX = x + 3;
            laser->beam.pos1.posY = y;
            laser->beam.pos2.posX = x + 2;
            laser->beam.pos2.posY = y;
            laser->beam.pos3.posX = x + 1;
            laser->beam.pos3.posY = y;
            laser->beam.rootPos.posX = x + 1;
            laser->beam.rootPos.posY = y;
            addLaser(laser,down);
            break;
        case laserLeft:
            laser->beam.pos1.posX = x;
            laser->beam.pos1.posY = y - 3;
            laser->beam.pos2.posX = x;
            laser->beam.pos2.posY = y - 2;
            laser->beam.pos3.posX = x;
            laser->beam.pos3.posY = y - 1;
            laser->beam.rootPos.posX = x;
            laser->beam.rootPos.posY = y - 1;
            addLaser(laser,left);
            break;
    }
    world[x][y] = laserTower;
}

/* Creates a SpikeTrap with two states.
 * Adds created SpikeTrap to the related Linked List.*/
static inline void CreateSpikeTraps(int x, int y)
{
    Spike *spike = malloc(sizeof(Spike));
    spike->pos.posX = x;
    spike->pos.posY = y;
    spike->delay = RANDOM_SHOOT;
    addSpike(spike);
}

/* Creates the moveable Player */
static inline void CreatePlayer(char c, int x, int y)
{
    Player *player = malloc(sizeof(Player));
    player->pos.posX = x;
    player->pos.posY = y;
    setPlayer(player);
    world[x][y] = c;
}

/* Creates the End. Player must reach this End. */
static inline void CreateEnd(char c, int x, int y)
{
    Player *end = malloc(sizeof(Player));
    end->pos.posX = x;
    end->pos.posY = y;
    setEnd(end);
    world[x][y] = c;
}

/* Creates the World by loading the Map file */
void createWorld()
{
    FILE *fp;
    const char *file = MAP_PATH;
    fp = fopen(file, "r");
    if(fp == NULL)
        fprintf(stderr, "Map not found!\n");
    char c;

    for(unsigned int x = 0; x < WORLD_SPACE; x++)
    {
        for(unsigned int y = 0; y < WORLD_SPACE; y++)
        {
            c = getc(fp);
            if(c == '\n')
                c = getc(fp);
            else if (c == cannonUp || c == cannonRight || c == cannonDown || c == cannonLeft)
            {
                CreateCannons(c, x, y);
            }
            else if(c == laserUp || c == laserRight || c == laserDown || c == laserLeft)
            {
                CreateLasers(c, x, y);
            }
            else if(c == spikeTrap)
            {
                CreateSpikeTraps(x, y);
            }
            else if(c == myplayer)
                CreatePlayer(c, x, y);
            else if(c == myend)
                CreateEnd(c, x, y);
            else
            {
                world[x][y] = c;
            }
        }
        c = getc(fp);
    }
    fclose(fp);
}

static void clearScreen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void DrawWorld()
{
    static int playerMoveDelay = PLAYER_MOVE_DELAY;
    updateCannonProjectiles();
    updateLaserBeams();
    updateSpikeTraps();
    for(unsigned int x = 0; x < WORLD_SPACE; x++)
    {
        for(unsigned int y = 0; y < WORLD_SPACE; y++)
        {
            printf("%c",world[x][y]);
        }
        printf("\n");
    }
    if(playerMoveDelay <= 0)
    {
        printf(PLAYER_MOVE1);
        updatePlayer();
        printf(PLAYER_MOVE2);
        updatePlayer();
        playerMoveDelay = PLAYER_MOVE_DELAY;
    }
    playerMoveDelay--;
    usleep(THIRTY_MS);
    clearScreen();
    if(checkPlayerHit())
    {
        printf(LOSE);
        exit(0);
    }
    if(checkOnEndTile())
    {
        printf(WIN);
        exit(0);
    }
}

int setTile(Tile tile, Position *position)
{
    if(position == NULL || world[position->posX][position->posY] == wall)
        return 1;
    world[position->posX][position->posY] = tile;
    return 0;
}

Tile getTile(Position *position)
{
    if(position == NULL)
    {
        fprintf(stderr, "Position should not be NULL!\n");
        exit(-1);
    }
    return (world[position->posX][position->posY]);
}
