//
// Created by adrianreimer on 7/23/19.
//

#include <stdio.h>
#include "Player.h"

static Player* player;
static Player* end;
static int moves;

void movePlayer(Direction direction)
{
    setTile(floor, &player->pos);
    switch(direction)
    {
        case up:
            player->pos.posX--;
            if(setTile(myplayer, &player->pos))
            {
                player->pos.posX++;
                setTile(myplayer, &player->pos);
            }
            break;
        case right:
            player->pos.posY++;
            if(setTile(myplayer, &player->pos))
            {
                player->pos.posY--;
                setTile(myplayer, &player->pos);
            }
            break;
        case down:
            player->pos.posX++;
            if(setTile(myplayer, &player->pos))
            {
                player->pos.posX--;
                setTile(myplayer, &player->pos);
            }
            break;
        case left:
            player->pos.posY--;
            if(setTile(myplayer, &player->pos))
            {
                player->pos.posY++;
                setTile(myplayer, &player->pos);
            }
            break;
    }
    moves++;
}

void setPlayer(Player *p)
{
    player = p;
}

void setEnd(Player *e)
{
    end = e;
}

/* Updates the Position of the Player */
inline void updatePlayer()
{
    char c;
    do
    {
        c = getchar();
    } while( c == '\n' || c == ' ');
    switch(c)
    {
        case 'W':
        case 'w':
            movePlayer(up);
            break;
        case 'D':
        case 'd':
            movePlayer(right);
            break;
        case 'S':
        case 's':
            movePlayer(down);
            break;
        case 'A':
        case 'a':
            movePlayer(left);
            break;
    }
}

/* Checks if Player got hit by an Entity */
int checkPlayerHit()
{
    if(player == NULL)
    {
        fprintf(stderr, "Player should not be NULL! Check Map for missing Player.\n");
        exit(-1);
    }
    return (getTile(&player->pos) != myplayer);
}

/* Checks if Player is on top of the end */
int checkOnEndTile()
{
    if(end == NULL)
    {
        fprintf(stderr, "End should not be NULL! Check Map for missing End.\n");
        exit(-1);
    }
    return ((player->pos.posX == end->pos.posX) && (player->pos.posY == end->pos.posY));
}
