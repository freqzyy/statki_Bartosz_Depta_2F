#include <iostream>
#include <limits>
#include "player.cc"
#include "ship.cc"
#include "board.cc"

using namespace std;

// Czysci konsole
void Clear() {
    cout << "\033[2J\033[1;1H";
}

// Zamiana z drugim graczem
void PlayersSwap()
{
    cout << "Nacisnij dowolny przycisk, aby zmienic sie z drugim graczem" << endl;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
    cin.get();
}

int main()
{
    Player player1;
    Player player2;
    player1.AddShips();
    player2.AddShips();

    cout << "Graczu 1 ustaw swoje statki:" << endl;
    player1.setupShips();

    PlayersSwap();
    Clear();
    
    cout << "Graczu 2 ustaw swoje statki:" << endl;
    player2.setupShips();
    
    Clear();

    int x,y;
    bool gameover = false;

    while (gameover == false)
    {
        cout << "Graczu 1, oto twoja plansza:" << endl;
        player1.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player1.shotsBoard.display(true);
        cout << "Podaj wspolrzedne strzalu(x,y): ";
        cin >> y >> x;
        player1.PlrShoot(player2, x, y);

        if (player2.noShipsLeft() == true)
        {
            cout << "Gracz 1 wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap();
        Clear();

        cout << "Graczu 2, oto twoja plansza:" << endl;
        player2.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player2.shotsBoard.display(true);
        cout << "Podaj wspolrzedne strzalu(x,y): ";
        cin >> y >> x;
        player2.PlrShoot(player1, x, y);


        if (player1.noShipsLeft() == true)
        {
            cout << "Gracz 2 wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap();
        Clear();
    };
    return 0;
}