#include "ship.h"

Ship::Ship()
{
}
Ship::Ship(int len)
{
    length_of_ship = len;
}

// Dodaje pozycje statku
void Ship::addPos(int index, int x, int y)
{
    if (index < length_of_ship)
    {
        x_pos[index] = x;
        y_pos[index] = y;
    }
}