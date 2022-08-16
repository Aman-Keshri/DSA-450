#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool iscowallocate(vector<int> &ar, int mid, int cow, int n)
{
    int distance = ar[0], cow_count = 1;

    for (int i = 1; i < n; i++)
    {
        if (ar[i] - distance >= mid)
        {
            cow_count++;
            distance = ar[i];
        }
        if (cow_count >= cow)
            return true;
    }
    return false;
}

int aggrcows(vector<int> &ar, int cow)
{
    int n = ar.size();
    sort(ar.begin(), ar.end());

    int start = 1;
    int end = ar[n - 1] - start;

    int mid = (start + end) >> 1;

    while (start <= end)
    {
        if (iscowallocate(ar, mid, cow, n))
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) >> 1;
    }
    return end;
}

int main()
{
    vector<int> a = {1, 2, 8, 4, 9};
    int cow = 3;

    cout << "largest of the Minimum is  " << aggrcows(a, cow) << endl;
    return 0;
}