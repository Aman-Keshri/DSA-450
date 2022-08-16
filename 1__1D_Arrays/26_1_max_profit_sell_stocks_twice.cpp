#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &a)
{
    int n = a.size();
    int buy1, buy2, profit1, profit2;
    buy1 = buy2 = INT32_MAX;
    profit1 = profit2 = 0;
    for (int i = 0; i < n; i++)
    {
        buy1 = min(buy1, a[i]);
        profit1 = max(profit1, a[i] - buy1);

        buy2 = min(buy2, a[i] - profit1);
        profit2 = max(profit2, a[i] - buy2);
    }

    return profit2;
}

int main()
{
    vector<int> a = {2, 30, 15, 10, 8, 25, 80};
    int ans = maxProfit(a);
    cout << ans;
    return 0;
}