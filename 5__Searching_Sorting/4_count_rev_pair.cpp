#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high)
{
    int pair = 0;
    int i = low, j = mid + 1;
    int left = low, right = mid + 1;
    vector<int> temp;

    for (i = low; i <= mid; i++)
    {
        while (j <= high && a[i] > 2 * (long long)a[j])
            j++;
        pair += (j - (mid + 1));
    }

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
            temp.push_back(a[left++]);
        else
            temp.push_back(a[right++]);
    }

    while (left <= mid)
        temp.push_back(a[left++]);
    while (right <= high)
        temp.push_back(a[right++]);

    for (int i = low; i <= high; i++)
        a[i] = temp[i - low];

    return pair;
}

int mergesort(vector<int> &a, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int pair = mergesort(a, low, mid);
    pair += mergesort(a, mid + 1, high);
    pair += merge(a, low, mid, high);
    return pair;
}

int reversePairs(vector<int> &a)
{
    return mergesort(a, 0, a.size() - 1);
}

int main()
{
    vector<int> arr = {2, 4, 3, 5, 1};
    cout << "The Total Reverse Pairs are -> " << reversePairs(arr);
    return 0;
}