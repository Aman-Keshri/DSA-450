#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void findSmallest(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int col = k / n;

    int row = k - (col * n);

    cout << arr[row][col] << endl;
}

int main()
{
    vector<vector<int>> arr = {{16, 28, 60, 64},
                               {22, 41, 63, 91},
                               {27, 50, 87, 93},
                               {36, 78, 87, 94}};
    int k = 7;
    cout << "kth smallest element is  ";
    findSmallest(arr, k - 1);
    return 0;
}