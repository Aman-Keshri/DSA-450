#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int profit(vector<int> a)
{
    int n = a.size();
    int maxi = 0, curprft = 0, low = 1e6;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < low)
            low = a[i];
        curprft = a[i] - low;
        if (curprft > maxi)
            maxi = curprft;
    }
    return maxi;
}

int main()
{
    vector<int> a = {7, 1, 5, 3, 6, 4};
    int ans = profit(a);
    cout << ans << endl;
    return 0;
}