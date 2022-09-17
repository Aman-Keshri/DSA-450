#include <bits/stdc++.h>
bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.
    bool flag = true;

    unordered_map<int, int> mp;
    for (auto i : arr1)
        mp[i]++;

    for (auto j : arr2)
        mp[j] > 0 ? mp[j]-- : flag = false;

    return flag;
}