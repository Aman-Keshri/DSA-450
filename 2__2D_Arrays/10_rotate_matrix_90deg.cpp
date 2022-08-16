#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &arr)
{
    int r = arr.size(), c = arr[0].size();
    vector<vector<int>> temp(r, vector<int>(c, 0));
    int row = 0, col = 0;

    for (int j = 0, row = 0; j < r; row++, j++)
    {
        for (int i = c - 1, col = 0; i >= 0; col++, i--)
            temp[row][col] = arr[i][j];
    }
    print(temp);
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr);
    cout << "Answer is \n";
    rotateMatrix(arr);
    return 0;
}