#include <bits/stdc++.h>
#include <unordered_map>

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int maxi = 0;
    int maxans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        maxi = max(maxi, mp[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxi == mp[arr[i]])
        {
            maxans = arr[i];
            break;
        }
    }
    return maxans;
}