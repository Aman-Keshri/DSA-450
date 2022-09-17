#include <bits/stdc++.h>
#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    unordered_map<int, int> mp;
    int temp = -1;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto x : mp)
    {
        if (x.second > n / 2)
        {
            temp = x.first;
        }
    }
    return temp;
}