#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y, n = 0;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {

        for (int i : {0, 1})
        {
            n++;
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (n >= 24)
            {
                if (boardPtr->checkGrid() == 1)
                {
                    cout << players[0]->to_string() << " wins\n";
                    return;
                }
                else if (boardPtr->checkGrid() == 2)
                {
                    cout << players[1]->to_string() << " wins\n";
                    return;
                }
                else
                    boardPtr->is_draw();
            }
        }
    }
}
