#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool validElement(vector<vector<char>> &board, pair<int, int> p, char element)
{
    // row check
    for (int col = 0; col < 9; col++)
        if (board[p.first][col] == element && col != p.second)
            return false;

    // column check
    for (int row = 0; row < 9; row++)
        if (board[row][p.second] == element && row != p.first)
            return false;

    // 3X3 grid
    int gridX = p.first / 3;
    int gridY = p.second / 3;
    for (int i = (gridX * 3); i < (gridX * 3) + 3; i++)
    {
        for (int j = (gridY * 3); j < (gridY * 3) + 3; j++)
        {
            if (board[i][j] == element && p.first != i && p.second != j)
                return false;
        }
    }

    return true;
}

pair<int, int> findEmpty(vector<vector<char>> &board)
{
    pair<int, int> p;
    p.first = -1, p.second = -1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '0')
            {
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    return p;
}

bool solve(vector<vector<char>> &board)
{
    int row, col;
    pair<int, int> pos = findEmpty(board);

    if (pos.first == -1 && pos.second == -1)
        return true;

    else
        row = pos.first, col = pos.second;

    for (int i = 1; i < 10; i++)
    {
        char element = '0' + i;
        if (validElement(board, pos, element))
        {
            board[row][col] = element;
            if (solve(board))
                return true;

            board[row][col] = '0';
        }
    }
    return false;
}

void print(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << "------------------------------------\n";

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
                cout << " | ";
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solveSudoku(vector<vector<char>> &board)
{
    bool status = solve(board);
    if (status)
        print(board);
    else
        cout << "Not possible\n";
}

int main()
{
    vector<vector<char>> grid = {{'3', '0', '6', '5', '0', '8', '4', '0', '0'},
                                 {'5', '2', '0', '0', '0', '0', '0', '0', '0'},
                                 {'0', '8', '7', '0', '0', '0', '0', '3', '1'},
                                 {'0', '0', '3', '0', '1', '0', '0', '8', '0'},
                                 {'9', '0', '0', '8', '6', '3', '0', '0', '5'},
                                 {'0', '5', '0', '0', '9', '0', '6', '0', '0'},
                                 {'1', '3', '0', '0', '0', '0', '2', '5', '0'},
                                 {'0', '0', '0', '0', '0', '0', '0', '7', '4'},
                                 {'0', '0', '5', '2', '0', '6', '3', '0', '0'}};
    print(grid);
    cout << "Answer is \n";
    solveSudoku(grid);
    return 0;
}