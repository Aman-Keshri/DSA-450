#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int start = 0, end = arr.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] - 1 - mid < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start + k;
}

int main()
{
    vector<int> a = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "kth missing number is  " << findKthPositive(a, k) << endl;
    return 0;
}