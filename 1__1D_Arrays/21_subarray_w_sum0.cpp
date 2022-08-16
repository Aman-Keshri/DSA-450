#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool sub_zero(vector<int> a)
{
    int n = a.size(), sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (mp[sum])
            return true;
        else
            mp[sum]++;
    }
    return false;
}

int main()
{
    vector<int> a = {2, 3, 4, 8, -7, -1, -9, 10};
    bool ans = sub_zero(a);
    cout << ans << endl;
    return 0;
}