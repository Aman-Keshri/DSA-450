#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>> &a)
{
    vector<vector<int>> merged;
    if (a.size() == 0)
        return merged;
    else
    {
        sort(a.begin(), a.end());
        vector<int> temp = a[0];

        for (auto it : a)
        {
            if (it[0] <= temp[1])
                temp[1] = max(it[1], temp[1]);
            else
            {
                merged.push_back(temp);
                temp = it;
            }
        }
        merged.push_back(temp);
    }
    return merged;
}

int main()
{
    vector<vector<int>> a = {{1, 4}, {2, 6}, {0, 3}, {5, 10}};
    vector<vector<int>> ans = merge_interval(a);
    for (auto it : ans)
    {
        cout << it[0] << ":" << it[1] << " ";
    }
    return 0;
}