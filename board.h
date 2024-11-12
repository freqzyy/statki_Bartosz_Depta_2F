#ifndef BOARD_H
#define BOARD_H
#include "ship.h"

class Board
{
private:
    /* data */
public:
    static const int size = 10;
    char board[size][size];
    Board();
    bool placeship(Ship &ship, int x, int y, char direction);
    bool shoot(int x,int y);
    void display(bool hideShips);
};
#endif