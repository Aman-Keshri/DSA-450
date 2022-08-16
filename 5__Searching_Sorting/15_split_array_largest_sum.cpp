#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &ar, int mid, int part)
{
    int sum = 0, c_parts = 1;
    for (int i = 0; i < ar.size(); i++)
    {
        if (sum + ar[i] <= mid)
            sum += ar[i];
        else
        {
            c_parts++;
            sum = ar[i];
        }
    }
    return (c_parts > part) ? false : true;
}

int splitarray(vector<int> &ar, int part)
{
    int start = INT32_MIN, end = 0;
    int n = ar.size();
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > start)
            start = ar[i];
        end += ar[i];
    }

    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ispossible(ar, mid, part))
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int m = 2;
    cout << "minimum largest sum possible   " << splitarray(a, m) << endl;
    return 0;
}