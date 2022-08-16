#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void small_array(vector<int> &a, int x)
{
    int n = a.size();
    int ans = INT32_MAX, sum = 0, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
            sum += a[end++];

        while (sum > x && start < n)
        {
            if (end - start < ans)
                ans = end - start;
            sum -= a[start++];
        }
    }
    cout << ans;
}

int main()
{
    vector<int> a = {1, 4, 45, 6, 10, 19};
    int m = 51;
    small_array(a, m);
    return 0;
}