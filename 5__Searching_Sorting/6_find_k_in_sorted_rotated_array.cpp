#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int pivotindex(vector<int> &arr)
{
    int end = arr.size() - 1;
    int start = 0;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }
        else
            end = mid;

        mid = start + (end - start) / 2;
    }
    return start;
}

int binarysearch(vector<int> &arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> a = {7, 8, 9, 10, 14, 18, 0, 1, 2, 4, 6};
    int n = a.size();
    int key = 4;
    int pivot = pivotindex(a);

    if (key >= a[pivot] && key <= a[n - 1])
        cout << "Element at index  " << binarysearch(a, pivot, n - 1, key) << endl;

    else
        cout << "Element at index  " << binarysearch(a, 0, (pivot - 1), key) << endl;

    return 0;
}