//
// Created by adrianreimer on 7/23/19.
//

#ifndef CONSOLEGAME_PLAYER_H
#define CONSOLEGAME_PLAYER_H

#include "../World/World.h"

typedef struct Player
{
    Position pos;
} Player;

void setPlayer(Player *p);
void setEnd(Player *e);
void updatePlayer();
int checkPlayerHit();
int checkOnEndTile();

#endif //CONSOLEGAME_PLAYER_H
