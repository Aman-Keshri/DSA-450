#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool triplet(vector<int> &a, int target)
{
    int n = a.size(), psum = 0;
    unordered_set<int> mp;

    for (int i = 0; i < n - 1; i++)
    {
        psum = target - a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (mp.find(psum - a[j]) != mp.end())
                return true;

            mp.insert(a[j]);
        }
    }
    return false;
}

int main()
{
    vector<int> a = {1, 4, 45, 6, 10, 8};
    int k = 22;
    if (triplet(a, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}