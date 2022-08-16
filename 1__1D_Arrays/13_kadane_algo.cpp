#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void kadane(vector<int> &a)
{
    int n = a.size();
    int sum = 0, maxi = -1e9;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > maxi)
            maxi = max(maxi, sum);

        if (sum < 0)
            sum = 0;
    }
    cout << maxi << endl;
}

int main()
{
    vector<int> a = {1, 4, 6, -9, 0, -2, 10, 20};
    kadane(a);
    return 0;
}