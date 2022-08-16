#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAX_ = 100;

int median(int arr[][MAX_], int n, int m)
{
    int maxi = INT32_MIN, mini = INT32_MAX;
    // find min and max
    for (int i = 0; i < n; i++)
    {
        if (mini > arr[i][0])
            mini = arr[i][0];

        if (maxi < arr[i][m - 1])
            maxi = arr[i][m - 1];
    }
    int count = (n * m + 1) / 2;
    int mid;

    while (mini < maxi)
    {
        mid = mini + (maxi - mini) / 2;
        int less_count = 0;

        for (int i = 0; i < n; i++)
            less_count += upper_bound(arr[i], arr[i] + m, mid) - arr[i];

        if (less_count < count)
            mini = mid + 1;
        else
            maxi = mid;
    }

    return mini;
}

int main()
{
    int r = 3, c = 3;
    int arr[][MAX_] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    int med = median(arr, r, c);
    cout << "median of matrix  " << med << endl;
    return 0;
}