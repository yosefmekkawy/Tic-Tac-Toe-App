#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;
#include "Tic_Board.cpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "GameManager.cpp"
int main()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');
    Board *bord = new Tic_Board();
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Choose Who Do You Want To Play Against\n1-Human\n2-Computer\n3-Ai Player \n";
    cin >> choice;
    if (choice == 1)
        players[1] = new Player(2, 'o');
    else if (choice == 2)
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 5);
    else
    {
        players[1] = new AI(bord, 'o');
    }
    GameManager x_o_game(bord, players);
    x_o_game.run();
    // system("pause");
}
