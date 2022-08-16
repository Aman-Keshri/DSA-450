#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void occur(vector<int> &a, int k)
{
    int n = a.size();
    int target = (n / k);
    unordered_map<int, int> mp;
    vector<int> temp;

    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (auto it : mp)
    {
        if (it.second > target)
            temp.push_back(it.first);
    }

    for (int i : temp)
        cout << i << " ";
}

int main()
{
    vector<int> a = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    occur(a, k);
    return 0;
}