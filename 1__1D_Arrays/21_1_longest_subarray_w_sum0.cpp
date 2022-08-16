#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int sub_zero(vector<int> a)
{
    int n = a.size(), sum = 0, maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
                maxi = max(maxi, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxi;
}

int main()
{
    vector<int> a = {2, 3, 4, 8, -7, -1, -9, 10};
    // 2 5 9 17 10 9 0 10
    int ans = sub_zero(a);
    cout << ans << endl;
    return 0;
}