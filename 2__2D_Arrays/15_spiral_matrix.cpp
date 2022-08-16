#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void spiral(int arr[4][4], int n, int m)
{

    int left = 0, right = m;
    int top = 0, bottom = n;

    while (left <= right && top <= bottom)
    {
        // top line
        for (int i = left; i < right; i++)
            cout << arr[top][i] << endl;
        top++;

        // right line
        for (int i = top; i < bottom; i++)
            cout << arr[i][right - 1] << endl;
        right--;

        // bottom line
        for (int i = right - 1; i >= left; i--)
            cout << arr[bottom - 1][i] << endl;
        bottom--;

        // left line
        for (int i = bottom - 1; i >= top; i--)
            cout << arr[i][left] << endl;
        left++;
    }
    cout << endl;
}

int main()
{
    int n = 4, m = 4;

    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    cout << "Spiral matrix is ";
    spiral(arr, n, m);

    return 0;
}