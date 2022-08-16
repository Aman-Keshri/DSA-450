#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int bi_search(int arr[][MAX], int r, int c, int cur_row)
{
    int low = 0, high = c - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[cur_row][mid] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low == c)
        return -1;
    else
        return low;
}

int max_1in_row(int arr[][MAX], int r, int c)
{
    int maxi = INT32_MIN, cur_len = 0, max_row = -1;

    for (int i = 0; i < r; i++)
    {
        int pos = bi_search(arr, r, c, i);
        if (pos == -1)
            cur_len = 0;
        else
            cur_len = c - pos;

        if (cur_len > maxi)
        {
            maxi = cur_len;
            max_row = i;
        }
    }
    return max_row;
}

int main()
{
    int r = 4, c = 4;
    int arr[][MAX] = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};

    int row = max_1in_row(arr, r, c);
    cout << "Max no of 1 is in Row  " << row << endl;
    return 0;
}