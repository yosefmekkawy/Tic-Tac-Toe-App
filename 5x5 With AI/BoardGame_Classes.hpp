#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;
#include <string>
class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board(int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual int is_winner(int a, int b, char symb) = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
    virtual int checkGrid() = 0;
    virtual int minimax(int &x, int &y, bool isMaximizing, bool first_time, int depth) = 0;
    virtual int check_status() = 0;
    virtual int is_moves_left() = 0;
};

class Tic_Board : public Board
{
public:
    Tic_Board();
    ~Tic_Board();
    bool update_board(int x, int y, char mark);
    int is_winner(int a, int b, char symb);
    bool is_draw();
    bool game_is_over();
    int checkGrid();
    void display_board();
    int minimax(int &x, int &y, bool isMaximizing, bool first_time, int depth);
    int check_status();
    bool is_valid(int x, int y);
    int is_moves_left();
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player
{
protected:
    string name;
    char symbol;

public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int &x, int &y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    // Take a symbol and pass it to parent
    RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int &x, int &y);
};

///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end
};
class AI : public Player
{
private:
    Board *board;

public:
    AI(Board *board, char symb) : Player(symb)
    {
        this->board = board;
        this->name = "AI Player";
        cout << "My Name Is " << this->name << endl;
    }
    void get_move(int &x, int &y)
    {
        board->minimax(x, y, false, true, 5);
    }
};
#endif
