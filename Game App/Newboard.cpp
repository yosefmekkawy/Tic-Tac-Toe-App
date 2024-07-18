#include<iostream>
#include"BoardGame_Classes.hpp"
#include<iomanip>

using namespace std;

Newboard::Newboard() {
    n_cols = 5;
    n_rows = 3;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
    }
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

void Newboard::display_board() {

    for (int i: {0, 1, 2}) {
        cout << '\n';

        for (int j: {0, 1, 2, 3, 4}) {
            if (i == 0) {
                if (j == 2) {
                    cout << "        ";
                    cout << "(" << i << "," << j << ")";
                    cout << setw(2) << board[i][j] << "  ";
                    break;
                } else {
                    cout << "    ";
                }

            } else if (i == 1 && j <= 3) {
                if (j == 0) {
                    cout << "      ";
                } else {
                    cout << "(" << i << "," << j << ")";
                    cout << setw(1) << board[i][j] << "    ";
                    if (j == 3)
                        break;
                }

            } else if (i == 2) {
                cout << "(" << i << "," << j << ")";
                if (j == 1) {
                    cout << " ";
                    cout << setw(1) << board[i][j] << " ";
                } else {
                    cout << setw(1) << board[i][j] << "  ";

                }
            }

        }
        cout << "\n---------------------------------------";
    }
    cout << endl;
}

//draw conditon
bool Newboard::is_draw() {
    return !(is_winner()) && n_moves == 9;
}

bool Newboard::is_winner() {
    //winner conditions
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == board[2][2] &&
        board[2][2] != 0) {
        return true;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0] &&
               board[2][0] != 0) {
        return true;
    } else if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[0][2] == board[2][4] &&
               board[2][4] != 0) {
        return true;
    } else if (board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][1] == board[1][3] &&
               board[1][3] != 0) {
        return true;
    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] &&
               board[2][2] != 0) {
        return true;
    } else if (board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][1] == board[2][3] &&
               board[2][3] != 0) {
        return true;
    } else if (board[2][2] == board[2][3] && board[2][3] == board[2][4] && board[2][2] == board[2][4] &&
               board[2][4] != 0) {
        return true;
    } else {
        return false;
    }
}

bool Newboard::update_board(int x, int y, char symbol) {
    if (x == 0) {
        if (y == 2 && board[x][y] == 0) {
            board[x][y] = toupper(symbol);
            n_moves++;
            return true;
        } else {
            return false;
        }
    } else if (x == 1) {
        if (y <= 3 && y != 0 && board[x][y] == 0) {
            board[x][y] = toupper(symbol);
            n_moves++;
            return true;
        } else {
            return false;
        }
    } else if (x == 2) {
        if (board[x][y] == 0 && y <= 4) {
            board[x][y] = toupper(symbol);
            n_moves++;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Newboard::game_is_over() {
    return n_moves >= 9;
}

