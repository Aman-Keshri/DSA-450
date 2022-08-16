#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int firstoccur(vector<int> &arr, int key)
{
    int end = arr.size() - 1;
    int start = 0;
    int first = 0;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return first;
}

int lastoccur(vector<int> &arr, int key)
{
    int end = arr.size() - 1;
    int start = 0;
    int last = 0;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return last;
}

int main()
{ // 0  1  2  3  4  5  6  7  8  9  10
    vector<int> a = {0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3};
    int key = 1;
    cout << "1st occur at index  " << firstoccur(a, key) << endl;
    cout << "Last occur at index  " << lastoccur(a, key) << endl;
    return 0;
}