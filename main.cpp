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
    cout << "Nacisnij ENTER, aby zmienic sie z drugim graczem" << endl;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
    cin.get();
    Clear();
    cout << "Kiedy drugi gracz bedzie gotowy, nacisnij ENTER" << endl;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
    Clear();
}

int main()
{
    Player player1;
    Player player2;
    player1.AddShips();
    player2.AddShips();
    
    cout << "Graczu 1 ustaw swoje statki:" << endl;
    player1.setupShips(player1);

    PlayersSwap();
    
    cout << "Graczu 2 ustaw swoje statki:" << endl;
    player2.setupShips(player2);
    
    PlayersSwap();

    int x,y;
    bool gameover = false;

    while (gameover == false)
    {
        cout << "Graczu 1, oto twoja plansza:" << endl;
        player1.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player1.shotsBoard.display(true);
        player1.PlrShoot(player2, x, y);

        if (player2.noShipsLeft() == true)
        {
            cout << "Gracz 1 wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap();

        cout << "Graczu 2, oto twoja plansza:" << endl;
        player2.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player2.shotsBoard.display(true);
        player2.PlrShoot(player1, x, y);


        if (player1.noShipsLeft() == true)
        {
            cout << "Gracz 2 wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap();
    };
    return 0;
}
