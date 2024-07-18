#include <iostream>
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "BoardGame_Classes.hpp"
#include "Newboard.cpp"
#include "four_in_a_row.cpp"
#include "GameManager.cpp"
#include "Tic_Board.cpp"
#include "X_O_Board.cpp"
using namespace std;

class game
{
private:
    Newboard *board;
    Player *players[2];

public:
    game(Newboard *boardptr, Player *playerptr[2])
    {
        board = boardptr;
        players[0] = playerptr[0];
        players[1] = playerptr[1];
    }

    void run()
    {
        int x, y;
        while (!board->game_is_over())
        {
            for (int i : {0, 1})
            {
                players[i]->get_move(x, y);
                while (!(board->update_board(x, y, players[i]->get_symbol())))
                {
                    players[i]->get_move(x, y);
                }
                board->display_board();
                if (board->is_winner())
                {
                    cout << players[i]->to_string() << " wins\n";
                    return;
                }
                if (board->is_draw())
                {
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }
};

class game2
{
private:
    Tic_Board *boardptr;
    Player *players[2];

public:
    game2(Tic_Board *bPtr, Player *playerPtr[2])
    {
        boardptr = bPtr;
        players[0] = playerPtr[0];
        players[1] = playerPtr[1];
    }

    void run()
    {
        int x, y, n = 0;

        boardptr->display_board();

        while (!boardptr->game_is_over())
        {

            for (int i : {0, 1})
            {
                n++;
                players[i]->get_move(x, y);
                while (!boardptr->update_board(x, y, players[i]->get_symbol()))
                {
                    players[i]->get_move(x, y);
                }
                boardptr->display_board();
                if (n >= 24)
                {
                    if (boardptr->checkGrid() == 1)
                    {
                        cout << players[0]->to_string() << " wins\n";
                        return;
                    }
                    else if (boardptr->checkGrid() == 2)
                    {
                        cout << players[2]->to_string() << " wins\n";
                        return;
                    }
                    else
                        boardptr->is_draw();
                }
            }
        }
    }
};

int main()
{
    int ac;
    cout << "\nChoose which game you would like to play:\n\n";
    cout << "1) 3x3 Tic-Tac-Toe:\n";
    cout << "2) Pyramidic Tic-Tac-Toe:\n";
    cout << "3) Connect Four:\n";
    cout << "4) 5*5 Tic-Tac-Toe:\n";
    cin >> ac;
    if (ac == 1)
    {
        int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
        system("pause");
    }
    else if (ac == 2)
    {
        Newboard a;
        char choice;
        Player *players[2];

        cout << "Welcome to Pyramadic Tic_Tac_Toe Game. :)\n";
        players[0] = new Player(1, 'x');

        cout << "Press 1 if you want to play with computer:\n";
        cout << "Press any charcter if you want to play with another player:\n";
        cin >> choice;
        if (choice != '1')
        {
            players[1] = new Player(2, 'o');
        }
        else
        {
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 5);
        }
        a.display_board();

        game x_o_game(new Newboard(), players);
        x_o_game.run();
        system("pause");
    }
    else if (ac == 3)
    {
        four_in_a_row a;
        char choice;
        Player *players[2];
        players[0] = new Player(1, 'x');
        cout << "Press 1 if you want to play with computer:\n";
        cout << "Press any charcter if you want to play with another player:\n";
        cin >> choice;
        if (choice != '1')
        {
            players[1] = new Player(2, 'o');
        }
        else
        {
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 5);
        }
        a.display_board();

        GameManager x_o_game(new four_in_a_row(), players);
        x_o_game.run();
        system("pause");
    }
    else if (ac == 4)
    {
        Tic_Board a;
        char choice;
        Player *players[2];
        players[0] = new Player(1, 'x');
        cout << "Press 1 if you want to play with computer:\n";
        cout << "Press any charcter if you want to play with another player:\n";
        cin >> choice;
        if (choice != '1')
        {
            players[1] = new Player(2, 'o');
        }
        else
        {
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 5);
        }
        a.display_board();

        game2 x_o_game(new Tic_Board(), players);
        x_o_game.run();
        system("pause");
    }
}
