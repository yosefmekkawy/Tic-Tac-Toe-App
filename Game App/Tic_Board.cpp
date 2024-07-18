#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"

using namespace std;

Tic_Board::Tic_Board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}


bool Tic_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void Tic_Board::display_board() {
    for (int i: {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
}

int Tic_Board::is_winnerr(int a, int b, char symb) {

    int row_win[3] = {0, 0, 0}, col_win[3] = {0, 0, 0}, diag_win[2] = {0, 0};
    for (int i: {0, 1, 2}) {
        if ((board[i + a][0 + b] == board[i + a][1 + b]) && (board[i + a][1 + b] == board[i + a][2 + b]) &&
            (board[i + a][2 + b] == symb))
            row_win[i]++;

        if ((board[0 + a][i + b] == board[1 + a][i + b]) && (board[1 + a][i + b] == board[2 + a][i + b]) &&
            (board[2 + a][i + b] == symb))

            col_win[i]++;
    }
    if (((board[0 + a][0 + b] == board[1 + a][1 + b]) && (board[1 + a][1 + b] == board[2 + a][2 + b]) &&
         (board[2 + a][2 + b] == symb)))
        diag_win[0]++;
    if (((board[2 + a][0 + b] == board[1 + a][1 + b]) && (board[1 + a][1 + b] == board[0 + a][2 + b]) &&
         (board[0 + a][2 + b] == symb)))
        diag_win[1]++;

    int sum = 0;
    for (int k: {0, 1, 2})
        sum += row_win[k] + col_win[k];
    sum += diag_win[0] + diag_win[1];
    return sum;
}

bool Tic_Board::is_winner() {
    return true;
}

bool Tic_Board::is_draw() {
    cout << "----\nDraw\n----";
    return true;
}

int Tic_Board::checkGrid() {
    int p1_wins = 0;
    int p2_wins = 0;
    // Check each 3x3 section
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            p1_wins += is_winnerr(i, j, 'X');
            p2_wins += is_winnerr(i, j, 'O');
        }
    }
    if (p1_wins > p2_wins)
        return 1;
    else if (p1_wins < p2_wins)
        return 2;
    else {
        return 3;

    }
}

bool Tic_Board::game_is_over() {
    return n_moves >= 24;
}