#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int findSum(int row, int col, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    int inf = INT32_MAX;
    if (row >= n || col >= m)
        return inf;
    if (row == n - 1 && col == m - 1)
        return arr[row][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    else
        return dp[row][col] = arr[row][col] + min(findSum(row + 1, col, n, m, arr, dp), findSum(row, col + 1, n, m, arr, dp));
}

int minPathSum(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), -1));
    return findSum(0, 0, arr.size(), arr[0].size(), arr, dp);
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};
    int path = minPathSum(arr);
    cout << "Min path Sum is   " << path << endl;

    return 0;
}