#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int counter = 0;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int left = 0, right = n, top = 0, bottom = n;

    while (left < right && top < bottom)
    {
        // top
        for (int i = left; i < right; i++)
            arr[top][i] = ++counter;
        top++;

        // right
        for (int i = top; i < bottom; i++)
            arr[i][right - 1] = ++counter;
        right--;

        // bottom
        for (int i = right - 1; i >= left; i--)
            arr[bottom - 1][i] = ++counter;
        bottom--;

        // left
        for (int i = bottom - 1; i >= top; i--)
            arr[i][left] = ++counter;
        left++;
    }

    return arr;
}

int main()
{
    int n = 5;
    vector<vector<int>> ar = generateMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}