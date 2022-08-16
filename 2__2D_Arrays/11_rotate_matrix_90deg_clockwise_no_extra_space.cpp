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
    // transpose the matrix
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reverse each row of matrix
    for (int i = 0; i < arr.size(); i++)
        reverse(arr[i].begin(), arr[i].end());

    print(arr);
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr);
    cout << "Answer is \n";
    rotateMatrix(arr);
    return 0;
}

// time = O(N^2)+O(N^2)