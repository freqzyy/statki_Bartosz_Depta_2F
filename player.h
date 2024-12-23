#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

using namespace std;

class Player :public Board
{
private:
    /* data */
public:
    Board ownBoard;
    Board shotsBoard;
    Ship ships[10];
    int lengths[10] = {1,1,1,1,2,2,2,3,3,4};
    string name;
    Player();
    void getName(Player &currentplayer);
    void AddShips();
    void setupShips(Player &currentplayer);
    void getShipPlacement(int &x, int &y, char &direction);
    bool noShipsLeft();
    bool PlrShoot(Player &opponent, int x, int y);
};

#endif
