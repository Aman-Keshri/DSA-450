#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void PascalElementfromrowCol(int row, int col)
{
    // row-1 C col-1
    if (col == 1 || col == row)
        cout << "1\n";
    else
    {
        double ans = 1;
        for (int i = 1; i < col; i++)
        {
            ans *= (row - i);
            ans /= (i);
        }
        cout << ans << endl;
    }
}

void generatenthRowPascal(int row)
{
    // n-1C0...n
    double ans = 1;
    cout << "1 ";
    for (int i = 1; i < row; i++)
    {
        ans *= (row - i);
        ans /= (i);
        // cout << row - i << " C " << i + 1 << "-- " << ans << endl;
        cout << ans << " ";
    }
    cout << endl;
}

void generatePascal(int row)
{
    vector<vector<int>> arr(row);

    for (int i = 0; i < row; i++)
    {
        arr[i].resize(i + 1);
        arr[i][0] = arr[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int rows = 5, col = 1;
    // generatePascal(rows);
    // generatenthRowPascal(rows);
    PascalElementfromrowCol(rows, col);
    return 0;
}