#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// brute force
//  Time - O{(N*M) * (N+M)}  Space - O(1)
void setRowZero(vector<vector<int>> &arr, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (arr[row][i] != 0 || arr[row][i] != -1)
            arr[row][i] = -1;
    }
}

void setColZero(vector<vector<int>> &arr, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] != 0 || arr[i][col] != -1)
            arr[i][col] = -1;
    }
}

void setMatrixZero(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                setRowZero(arr, i, col);
                setColZero(arr, j, row);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

// Use Dummy array
// Time - O{2*(N*M)}  Space - O(N)+O(M)
void setMatrixZeroI(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    vector<int> rowzero(row, -1);
    vector<int> colzero(col, -1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                rowzero[i] = 0;
                colzero[j] = 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (rowzero[i] == 0 || colzero[j] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }
}

// same approach without dummy array
// Time - O{2*(N*M)}   Space - O(1)

void setMatrixZeroII(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    int flag = 1;

    for (int i = 0; i < row; i++)
    {
        if (arr[i][0] == 0)
            flag = 0;
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[0][j] = arr[i][0] = 0;
            }
        }
    }

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 1; j--)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
                arr[i][j] = 0;
        }
        if (flag == 0)
            arr[i][0] = 0;
    }
}
void print(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 0}, {0, 1, 1, 1}};
    print(arr);
    // setMatrixZero(arr);
    // setMatrixZeroI(arr);
    setMatrixZeroII(arr);
    print(arr);
    return 0;
}