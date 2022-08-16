/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int findpath(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (row >= arr.size() || col >= arr[0].size())
        return 0;
    if (arr[row][col] == 1)
        return 0;
    if (row == arr.size() - 1 && col == arr[0].size() - 1)
        return 1;
    if (dp[row][col] != -1)
        return dp[row][col];
    else
        return dp[row][col] = findpath(row + 1, col, arr, dp) + findpath(row, col + 1, arr, dp);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

    return findpath(0, 0, obstacleGrid, dp);
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}};
    int path = uniquePathsWithObstacles(arr);
    cout << "total unique path  " << path << endl;
    return 0;
}