#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &arr, int m, int h)
{
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        if (arr[i] % m == 0)
        {
            int k = arr[i] / m;
            cnt += k;
        }
        else
        {
            int k = (arr[i] / m) + 1;
            cnt += k;
        }
        if (cnt > h)
        {
            return false;
        }
    }
    return true;
}

int kokobanana(vector<int> &ar, int hours)
{
    int start = INT32_MAX, end = INT32_MIN;
    int n = ar.size();
    for (int i = 0; i < n; i++)
    {
        if (ar[i] < start)
            start = ar[i];
        if (ar[i] > end)
            end = ar[i];
    }
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (ispossible(ar, mid, hours))
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

int main()
{
    vector<int> a = {3, 6, 7, 11};
    int hr = 8;
    cout << "Least spped of eating banana is  " << kokobanana(a, hr) << endl;
    return 0;
}