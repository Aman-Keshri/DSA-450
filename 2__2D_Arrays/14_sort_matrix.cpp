#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MAX = 100;

void merge(vector<int> &temp, int low, int high, int mid)
{
    // int start = low, end = mid + 1, k = low;
    // vector<int> ar;
    // while (start <= mid && end <= high)
    // {
    //     if (temp[start] <= temp[end])
    //         ar[k++] = (temp[start++]);
    //     else
    //         ar[k++] = (temp[end++]);
    // }

    // while (start <= mid)
    //     ar[k++] = temp[start++];

    // while (end <= high)
    //     ar[k++] = temp[end++];

    // for (int i = low; i <= high; i++)
    //     temp[i] = ar[i - low];
    vector<int> t;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (temp[left] <= temp[right])
            t.push_back(temp[left++]);
        else
            t.push_back(temp[right++]);
    }

    while (left <= mid)
        t.push_back(temp[left++]);

    while (right <= high)
        t.push_back(temp[right++]);

    for (int i = low; i <= high; i++)
        temp[i] = t[i - low];
}

vector<int> merge_sort(vector<int> &arr, int low, int high)
{
    int mid = (high + low) / 2;
    if (high > low)
    {
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
    return arr;
}

void sort_matrix(vector<vector<int>> &arr, int r, int c)
{
    vector<int> temp;
    int k = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp.push_back(arr[i][j]);

    temp = merge_sort(temp, 0, (r * c) - 1);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = temp[k++];
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int r = 4, c = 4;
    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};
    sort_matrix(arr, r, c);

    return 0;
}