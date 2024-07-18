#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i:
                {
                    0,1
                })
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            cout << endl;
            if (boardPtr->is_winner())
            {
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
// This method creates board and players
// It displays board
// While True
//   For each player
//      It takes a valid move as x, y pair (between 0 - 2)
//      It updates board and displays otit
//      If winner, declare so and end
//      If draw, declare so and end
