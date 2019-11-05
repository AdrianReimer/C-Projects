//
// Created by adrianreimer on 11/5/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Salesforce.

    Connect 4 is a game where opponents take turns dropping red or black discs into a 7 x 6 vertically suspended grid.
    The game ends either when one player creates a line of four consecutive discs of their color
    (horizontally, vertically, or diagonally), or when there are no more spots left in the grid.

    Design and implement Connect 4.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "day61.h"

#define WIN_DISC_AMT 4

const char *RED_DISC_SYMBOL = "R ";
const char *BLACK_DISC_SYMBOL = "B ";
const char *NONE_DISC_SYMBOL = "- ";
const char *GRID_FULL_TEXT = "Grid is full! Tie.\n";
const char *COL_FULL_TEXT = "That Column is full! Please try another one.";
const char *PLAYER_WIN_TEXT = "Player %d Won!";


static uint8_t
gridIsFull(ConnectFourGame *game)
{
    for(int8_t i = 0; i < GRID_COLS; i++) {
        if(game->vPos[i] < GRID_ROWS) {
            return 0;
        }
    }
    return 1;
}

static uint8_t
checkHorizontalRight(ConnectFourGame *game, uint8_t col)
{
    uint8_t colorCnt = 0;
    for(int8_t i = col; i < GRID_COLS; i++) {
        if(game->grid[game->vPos[col]][i] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkHorizontalLeft(ConnectFourGame *game, uint8_t col)
{
    uint8_t colorCnt = 0;
    for(int8_t i = col; i >= 0; i--) {
        if(game->grid[game->vPos[col]][i] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkVerticalUp(ConnectFourGame *game, uint8_t col)
{
    uint8_t colorCnt = 0;
    for(int8_t i = game->vPos[col]; i < GRID_ROWS; i++) {
        if(game->grid[i][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkVerticalDown(ConnectFourGame *game, uint8_t col)
{
    uint8_t colorCnt = 0;
    for(int8_t i = game->vPos[col]; i >= 0; i--) {
        if(game->grid[i][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkDiagonalLeftUp(ConnectFourGame *game, int8_t col)
{
    uint8_t colorCnt = 0;
    int8_t row = game->vPos[col];
    while(col >= 0 && row >= 0) {
        if(game->grid[row][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
        col--;
        row--;
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkDiagonalLeftDown(ConnectFourGame *game, int8_t col)
{
    uint8_t colorCnt = 0;
    int8_t row = game->vPos[col];
    while(col >= 0 && row < GRID_ROWS) {
        if(game->grid[row][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
        col--;
        row++;
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkDiagonalRightUp(ConnectFourGame *game, int8_t col)
{
    uint8_t colorCnt = 0;
    int8_t row = game->vPos[col];
    while(col < GRID_COLS && row >= 0) {
        if(game->grid[row][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
        col++;
        row--;
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

static uint8_t
checkDiagonalRightDown(ConnectFourGame *game, int8_t col)
{
    uint8_t colorCnt = 0;
    int8_t row = game->vPos[col];
    while(col < GRID_COLS && row < GRID_ROWS) {
        if(game->grid[row][col] == game->currentPlayer) {
            colorCnt++;
        } else {
            break;
        }
        col++;
        row++;
    }
    return (colorCnt >= WIN_DISC_AMT) ? 1 : 0;
}

void
printGrid(ConnectFourGame *game)
{
    printf("\n");
    for(size_t x = 0; x < GRID_ROWS; x++) {
        for(size_t y = 0; y < GRID_COLS; y++) {
            if(game->grid[x][y] == Red) {
                printf(RED_DISC_SYMBOL);
            } else if(game->grid[x][y] == Black) {
                printf(BLACK_DISC_SYMBOL);
            } else if(game->grid[x][y] == None) {
                printf(NONE_DISC_SYMBOL);
            }
        }
        printf("\n");
    }
    printf("\n");
}

static void
changePlayer(ConnectFourGame *game)
{
    switch (game->currentPlayer) {
        case P1:
            game->currentPlayer = P2;
            break;
        case P2:
            game->currentPlayer = P1;
            break;
    }
}

uint8_t
connectFourMove(ConnectFourGame *game, uint8_t col)
{
    if(game == NULL) {
        fprintf(stderr, "ConnectFourGame should not be NULL!");
        return 0;
    }
    if(game->vPos[col] >= GRID_ROWS) {
        printf(COL_FULL_TEXT);
        return 0;
    }

    game->grid[game->vPos[col]][col] = game->currentPlayer;
    printGrid(game);
    if(checkDiagonalLeftDown(game, col) || checkDiagonalLeftUp(game, col) ||
       checkDiagonalRightDown(game, col) || checkDiagonalRightUp(game, col) ||
       checkHorizontalLeft(game, col) || checkHorizontalRight(game, col) ||
       checkVerticalDown(game, col) || checkVerticalUp(game, col)) {
        printf(PLAYER_WIN_TEXT, game->currentPlayer);
        return 1;
    }
    game->vPos[col]++;
    if(gridIsFull(game)) {
        printf(GRID_FULL_TEXT);
        return 1;
    }
    changePlayer(game);
    return 0;
}

void
connectFourTestDiagonal()
{
    ConnectFourGame game = {P1};
    connectFourMove(&game, 0);
    connectFourMove(&game, 1);
    connectFourMove(&game, 1);
    connectFourMove(&game, 2);
    connectFourMove(&game, 2);
    connectFourMove(&game, 3);
    connectFourMove(&game, 2);
    connectFourMove(&game, 5);
    connectFourMove(&game, 3);
    connectFourMove(&game, 3);
    assert(connectFourMove(&game, 3));
}

void
connectFourTestVertical()
{
    ConnectFourGame game = {P1};
    connectFourMove(&game, 0);
    connectFourMove(&game, 1);
    connectFourMove(&game, 0);
    connectFourMove(&game, 1);
    connectFourMove(&game, 0);
    connectFourMove(&game, 1);
    assert(connectFourMove(&game, 0));
}

void
connectFourTestHorizontal()
{
    ConnectFourGame game = {P2};
    connectFourMove(&game, 0);
    connectFourMove(&game, 0);
    connectFourMove(&game, 1);
    connectFourMove(&game, 1);
    connectFourMove(&game, 2);
    connectFourMove(&game, 2);
    assert(connectFourMove(&game, 3));
}
