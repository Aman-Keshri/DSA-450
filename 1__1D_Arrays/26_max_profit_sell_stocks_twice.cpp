#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &a)
{
    int n = a.size();

    int maxi = a[n - 1], mini = a[0];
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxi)
            maxi = a[i];
        dp[i] = max(dp[i + 1], maxi - a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] < mini)
            mini = a[i];
        dp[i] = max(dp[i - 1], dp[i] + (a[i] - mini));
    }

    return dp[n - 1];
}

int main()
{
    vector<int> a = {3, 3, 5, 0, 0, 3, 1, 4};
    int ans = maxProfit(a);
    cout << ans;
    return 0;
}