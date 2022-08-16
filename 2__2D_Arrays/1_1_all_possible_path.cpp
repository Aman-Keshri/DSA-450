#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// recursive approach Time - O(2^n*m)
int findAllpossiblePath(int i, int j, int row, int col)
{
    if (i >= row || j >= col)
        return 0;
    if (i == row - 1 && j == col - 1)
        return 1;
    else
        return findAllpossiblePath(i + 1, j, row, col) + findAllpossiblePath(i, j + 1, row, col);
}

// recurssive approach Time - O(n*m) Space - O(n*m)
int findAllpossiblePath_recursive(int i, int j, int row, int col, vector<vector<int>> &dp)
{
    if (i >= row || j >= col)
        return 0;
    if (i == row - 1 && j == col - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = findAllpossiblePath(i + 1, j, row, col) + findAllpossiblePath(i, j + 1, row, col);
}

// using Combination approach Time O(row-1) or O(col-1) Space - O(1)
int findAllpossiblePath_optimal(int row, int col)
{
    int N = row + col - 2;
    int r = row - 1;
    double ans = 1;

    // combination of nCr e.g. 10 C 3  (8*9*10)/(1*2*3)
    //                             {(10-3+1)/1} * {(10-3+2)/2} * {(10-3+3)/3}
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return (int)ans;
}

int main()
{
    int row = 2, col = 3;
    int path = findAllpossiblePath_optimal(row, col);
    cout << "All possible paths are  " << path << endl;

    return 0;
}