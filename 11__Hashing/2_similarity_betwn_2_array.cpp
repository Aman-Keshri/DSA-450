#include <bits/stdc++.h>
#include <unordered_map>

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
{
    // Write Your Code here.
    unordered_map<int, int> mp;

    for (int i = 0; i < arr1.size(); i++)
        mp[arr1[i]]++;

    for (int i = 0; i < arr2.size(); i++)
        mp[arr2[i]]++;

    int uni = 0, inter = 0;
    for (auto i : mp)
    {
        if (i.second >= 2)
            inter++;
        uni++;
    }
    pair<int, int> ans(inter, uni);

    return ans;
}