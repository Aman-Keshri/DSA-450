#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int pair_sum(vector<int> &a, int target)
{
    int n = a.size();
    int count = 0, val;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        val = target - a[i];
        if (mp[val])
            count += mp[val];

        mp[a[i]]++;
    }
    return count;
}

int main()
{
    vector<int> a = {1, 5, 7, 1};
    int psum = pair_sum(a, 6);
    cout << psum;
    return 0;
}