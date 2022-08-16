#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_prod(vector<int> &a)
{
    int n = a.size();
    int ans, maxi, mini;
    ans = maxi = mini = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
            swap(maxi, mini);

        maxi = max(a[i], maxi * a[i]);
        mini = min(a[i], mini * a[i]);
        ans = max(ans, maxi);
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 3, -2, 4};
    int ans = max_prod(a);
    cout << ans << endl;
    return 0;
}