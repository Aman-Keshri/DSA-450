#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int peakindex(vector<int> &arr)
{
    int end = arr.size() - 1;
    int start = 0;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
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
    vector<int> a = {0, 1, 2, 4, 6, 2, 1, 0};
    cout << "Peak at index  " << peakindex(a) << endl;
    return 0;
}