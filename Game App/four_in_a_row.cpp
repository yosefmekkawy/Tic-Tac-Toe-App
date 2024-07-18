#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

four_in_a_row::four_in_a_row()
{
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for(int i=0; i<n_rows; i++)
    {
        board[i] = new char[n_cols];
        for(int j=0; j<n_cols; j++)
        {
            board[i][j] = '-';
        }
    }
}

bool four_in_a_row::update_board(int x, int y, char mark)
{
    if(n_moves >= n_rows * n_cols)
    {
        return false;
    }

    if(x < 0 || x >= n_rows || y < 0 || y >= n_cols || board[x][y] != '-')
    {
        return false;
    }

    board[x][y] = mark;
    n_moves++;
    return true;
}

void four_in_a_row::display_board()
{
    for(int i=0; i<n_rows; i++)
    {
        for(int j=0; j<n_cols; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool four_in_a_row::is_winner()
{
    // check for 4-in-a-row horizontally
    for(int i=0; i<n_rows; i++)
    {
        for(int j=0; j<n_cols-3; j++)
        {
            if(board[i][j] != '-' && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3])
            {
                return true;
            }
        }
    }

    // check for 4-in-a-row vertically
    for(int i=0; i<n_rows-3; i++)
    {
        for(int j=0; j<n_cols; j++)
        {
            if(board[i][j] != '-' && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j])
            {
                return true;
            }
        }
    }

    // check for 4-in-a-row diagonally (left to right)
    for(int i=0; i<n_rows-3; i++)
    {
        for(int j=0; j<n_cols-3; j++)
        {
            if(board[i][j] != '-' && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3])
            {
                return true;
            }
        }
    }

    // check for 4-in-a-row diagonally (right to left)
    for(int i=0; i<n_rows-3; i++)
    {
        for(int j=3; j<n_cols; j++)
        {
            if(board[i][j] != '-' && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3])
            {
                return true;
            }
        }
    }

    return false;
}

bool four_in_a_row::is_draw()
{
    return n_moves == n_rows * n_cols;
}

bool four_in_a_row::game_is_over()
{
    return is_winner() || is_draw();
}
