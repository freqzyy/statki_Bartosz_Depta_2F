#include "board.h"
#include <iostream>

using namespace std;


Board::Board()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = '#';
        }
    }
}

// Funkcja stawiajaca statki

bool Board::placeship(Ship &ship, int x, int y, char direction)
{
    if (direction == 'v' && x + ship.length_of_ship > size)
    {
        return false;
    }
    if (direction == 'h' && y + ship.length_of_ship > size)
    {
        return false;
    }

    if (direction == 'v')
    {
        for (int i = 0; i < ship.length_of_ship; i++)
        {
            int row = x + i;
            if (board[row][y] != '#')
            {
                return false;
            }
        }
    }
    else if (direction == 'h')
    {
        for (int i = 0; i < ship.length_of_ship; i++)
        {
            int col = y + i;
            if (board[x][col] != '#')
            {
                return false;
            }
        }
    }
    
    if (direction == 'v')
    {
        for (int i = 0; i < ship.length_of_ship; i++)
        {
            int row = x + i;
            board[row][y] = 'S';
        }
    }
    else if (direction == 'h')
    {
        for (int i = 0; i < ship.length_of_ship; i++)
        {
            int col = y + i;
            board[x][col] = 'S';
        }
    }
    return true;
}
        
// Wyswietlanie planszy z lub bez statkow

void Board::display(bool hideShips)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (hideShips == true && board[i][j] == 'S')
            {
                cout << "# ";
            }
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Strzelanie

bool Board::shoot(int x,int y)
{
    if (board[x][y] == 'S')
    {
        board[x][y] = 'X';
        return true;
    }
    else if (board[x][y] == '#')
    {
        board[x][y] = 'O';
    }
    return false;
}
