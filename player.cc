#include "player.h"
#include <iostream>

using namespace std;

Player::Player()
{
}

void Player::getName(Player &currentplayer)
{
    cin >> currentplayer.name;
}

// Dodanie statkow graczom

void Player::AddShips()
{
    for (int i = 0; i < 10; i++)
    {
        ships[i] = Ship(lengths[i]);
    }
}

// Stawianie statkow

void Player::setupShips(Player &currentplayer)
{
    for (int i = 0; i < 10; i++)
    {
        currentplayer.ownBoard.display(false);
        cout << "Postaw " << ships[i].length_of_ship << "-masztowiec" << endl;
        int x,y;
        char direction;
        bool placed = false;
        do 
        {
            getShipPlacement(x, y, direction);
            placed = ownBoard.placeship(ships[i], x, y, direction);
            if (!placed)
            {
                cout << "Nie mozna umiescic tutaj statku, statek wystawalby poza plansze lub stykalby sie z innym statkiem" << endl;
                currentplayer.ownBoard.display(false);
            }
            else
            {
                cout << "Statek pomyslnie ustawiony na pozycji: (" << x << ", " << y << ")" << " z kierunkiem: " << direction << endl;
            }
        }
        while (!placed);
    }
}

// Pozycja statku

void Player::getShipPlacement(int &x, int &y, char &direction)
{
    bool validInput = false;

    while (!validInput)
    {
        cout << "Podaj wiersz(0-" << size - 1 << "): ";
        cin >> x;
        if (cin.fail())
        {
            cout << "Podaj liczbe calkowita" << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
        else if (x < 0)
        {
            cout << "Podana liczba jest mniejsza od zera" << endl;
        }
        else if(x >= size)
        {
            cout << "Podana liczba jest wieksza od rozmiaru planszy" << endl;
        }
        else
        {
            validInput = true;
        }
    }

    validInput = false;
    
    while (!validInput)
    {
        cout << "Podaj kolumne(0-" << size - 1 << "): ";
        cin >> y;
        if (cin.fail())
        {
            cout << "Podaj liczbe calkowita" << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
        else if (y < 0)
        {
            cout << "Podana liczba jest mniejsza od zera" << endl;
        }
        else if(y >= size)
        {
            cout << "Podana liczba jest wieksza od rozmiaru planszy" << endl;
        }
        else
        {
            validInput = true;
        }
    }

    validInput = false;

    while (!validInput)
    {
        cout << "Podaj kierunek (h - poziomo,  v - pionowo): ";
        cin >> direction;

        if (direction == 'h' || direction == 'v')
        {
            validInput = true;
        }
        else
        {
            cout << "Podany kierunek jest niepoprawny" << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
        }
    }
}

// Sprawdzenie czy gracz nie ma juz statkow/czy drugi gracz wygral 

bool Player::noShipsLeft()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (ownBoard.board[i][j] == 'S')
            {
                return false;
            }
        }
    }
    return true;
}

// Sprawdzanie czy gracz trafil w statek i czy wpisal dobre wspolrzedne

bool Player::PlrShoot(Player &opponent, int x, int y)
{

    bool validInput = false;

    do
    {
        cout << "Podaj wspolrzedne strzalu(wiersz - (0-9),kolumna - (0-9)):";
        cin >> x >> y;
        if (cin.fail() || x < 0 || x >= size || y < 0 || y >= size)
        {
            cout << "Niepoprawne wspolrzedne" << endl;
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
            continue;
        }

        validInput = true;
    } 
    while (!validInput);

    bool hit = opponent.ownBoard.shoot(x,y);
    if (hit)
    {
        shotsBoard.board[x][y] = 'X';
        cout << "Trafiony!" << endl;
    }
    else
    {
        shotsBoard.board[x][y] = 'O';
        cout << "Pudlo!" << endl;
    }
    return hit;
}
