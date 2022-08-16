#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void distribution(vector<int> &a, int m)
{
    int n = a.size();
    int total = INT32_MAX;

    sort(a.begin(), a.end());

    for (int i = 0; i + m - 1 < n; i++)
        total = min(total, a[i + m - 1] - a[i]);

    cout << total;
}

int main()
{
    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;
    distribution(a, m);
    return 0;
}