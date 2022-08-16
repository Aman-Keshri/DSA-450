#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, vector<int> &temp, int low, int mid, int high)
{
    int i = low, j = mid + 1, inv = 0, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            inv += (mid - i + 1);
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (int i = low; i <= high; i++)
        a[i] = temp[i];

    return inv;
}

int mergesort(vector<int> &a, vector<int> &temp, int low, int high)
{
    int inv = 0, mid;
    if (high > low)
    {
        mid = (low + high) / 2;
        inv += mergesort(a, temp, low, mid);
        inv += mergesort(a, temp, mid + 1, high);

        inv += merge(a, temp, low, mid, high);
    }

    return inv;
}

int inversion(vector<int> &a)
{
    int n = a.size();
    vector<int> temp(n);
    int inv = mergesort(a, temp, 0, n);
    return inv;
}

int main()
{
    vector<int> a = {5, 3, 2, 1, 4};
    int ans = inversion(a);
    cout << ans << endl;
    return 0;
}