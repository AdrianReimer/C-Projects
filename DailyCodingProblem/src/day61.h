//
// Created by adrianreimer on 11/5/19.
//

#ifndef DAILYCODINGPROBLEM_DAY61_H
#define DAILYCODINGPROBLEM_DAY61_H

#include <inttypes.h>

#define GRID_ROWS 7
#define GRID_COLS 6

typedef enum {
    P1 = 1, P2 = 2
} Player;

typedef enum {
    None = 0, Red = P1, Black = P2
} Color;

typedef struct {
    Player currentPlayer;
    uint8_t vPos[GRID_COLS];
    Color grid[GRID_ROWS][GRID_COLS];
} ConnectFourGame;

uint8_t connectFourMove(ConnectFourGame *game, uint8_t col);
void connectFourTestDiagonal();
void connectFourTestVertical();
void connectFourTestHorizontal();

#endif //DAILYCODINGPROBLEM_DAY61_H
