#include <bits/stdc++.h>

void addtoAns(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // since we are filling board column wise in left to right fashion
    // it is not required to check on left side of board for valid queen
    // and column check is also not required as we only fill one queen in a col

    // check for same row
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // check for upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    // at end if all cases pass
    return true;
}

// optimising the isSafe function to O(1) time using hashmap
/*
    for same row
    keep map of row number and queen present or not
    map of int and bool

    for lower diagonal
    keep map of sum of row+col and queen present or not

    for upper diagonal
    use formula  -  (n-1) + (col-row)
    keep map of formula and queen present or not

*/

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if (col == n)
    {
        addtoAns(ans, board, n);
        return;
    }

    // solve for 1 col rest recurssion will do
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // set board to 1
            board[row][col] = 1;
            // move to next column
            solve(col + 1, ans, board, n);
            // backtrack and reset queen
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}