#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &ar, int mid, int days)
{
    int sum = 0, c_days = 1;
    for (int i = 0; i < ar.size(); i++)
    {
        if (sum + ar[i] <= mid)
        {
            sum += ar[i];
        }
        else
        {
            c_days++;
            sum = ar[i];
        }
    }
    if (c_days > days)
        return false;
    else
        return true;
}

int shipwieght(vector<int> &ar, int days)
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
        if (ispossible(ar, mid, days))
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 5;
    cout << "Least max weight is  " << shipwieght(a, d) << endl;
    return 0;
}