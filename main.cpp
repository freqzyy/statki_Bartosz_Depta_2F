#include <iostream>
#include <limits>
#include "player.cc"
#include "ship.cc"
#include "board.cc"

using namespace std;

// Czysci konsole
void Clear() 
{
    system("cls");
}

// Zamiana z drugim graczem
void PlayersSwap(Player &secondplayer)
{
    cout << "=========================" << endl;
    cout << "     ZAMIANA GRACZY" << endl;
    cout << "=========================" << endl;
    cout << "Nacisnij ENTER i odejdz od komputera" << endl;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
    cin.get();
    Clear();
    cout << secondplayer.name << " nacisnij ENTER, aby grac" << endl;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
    Clear();
}

int main()
{
    Player player1;
    Player player2;
    player1.AddShips();
    player2.AddShips();
    
    cout << "Podaj imie gracza pierwszego: ";
    player1.getName(player1);
    cout << "Podaj imie gracza drugiego: ";
    player2.getName(player2);

    cout << player1.name << " ustaw swoje statki:" << endl;
    player1.setupShips(player1);

    PlayersSwap(player2);
    
    cout << player2.name << " ustaw swoje statki:" << endl;
    player2.setupShips(player2);
    
    PlayersSwap(player1);

    int x,y;
    bool gameover = false;

    while (!gameover)
    {
        cout << player1.name << ", oto twoja plansza:" << endl;
        player1.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player1.shotsBoard.display(true);
        player1.PlrShoot(player2, x, y);

        if (player2.noShipsLeft())
        {
            cout << player1.name << " wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap(player2);

        cout << player2.name << ", oto twoja plansza:" << endl;
        player2.ownBoard.display(false);
        cout << "Plansza przeciwnika:" << endl;
        player2.shotsBoard.display(true);
        player2.PlrShoot(player1, x, y);


        if (player1.noShipsLeft())
        {
            cout << player2.name << " wygral!" << endl;
            gameover = true;
            break;
        }

        PlayersSwap(player1);
    };
    return 0;
}
