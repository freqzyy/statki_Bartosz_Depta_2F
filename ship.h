#ifndef SHIP_H
#define SHIP_H

class Ship
{
public:
    int length_of_ship;
    int x_pos[4];
    int y_pos[4];
    Ship();
    Ship(int len);
    void addPos(int index,int x,int y);
};
#endif