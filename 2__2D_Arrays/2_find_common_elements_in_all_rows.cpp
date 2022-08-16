#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void commoninRows(vector<vector<int>> &arr)
{
    unordered_map<int, int> mp;
    int row = arr.size(), col = arr[0].size();

    for (int i = 0; i < col; i++)
        mp[arr[0][i]] = 1;

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mp[arr[i][j]] == i)
            {
                mp[arr[i][j]] = i + 1;

                if (i == row - 1 && mp[arr[i][j]] == row)
                    cout << arr[i][j] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 1, 4, 8},
                               {3, 7, 8, 5, 1},
                               {8, 7, 7, 3, 1},
                               {8, 1, 2, 7, 9}};

    cout << "common elements in all rows is/are  ";
    commoninRows(arr);
    return 0;
}