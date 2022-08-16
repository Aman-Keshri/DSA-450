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

int main()
{
    vector<int> a = {7, 8, 9, 10, 14, 18, 0, 1, 2, 4, 6};
    cout << "Pivot at index  " << pivotindex(a) << endl;
    return 0;
}