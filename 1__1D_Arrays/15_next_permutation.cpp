#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> rev(vector<int> a, int i)
{
    int n = a.size();
    int first = i, last = n - 1;

    while (first < last)
    {
        swap(a[first], a[last]);
        first++;
        last--;
    }
    return a;
}
vector<int> nxt_prm(vector<int> a)
{
    int n = a.size();
    int i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            break;
    }
    if (i < 0)
        a = rev(a, 0);
    else
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (a[j] > a[i])
                break;
        }
        swap(a[i], a[j]);
        a = rev(a, i + 1);
    }
    return a;
}

int main()
{
    vector<int> a = {1, 2, 3};
    int n = a.size();
    vector<int> ans = nxt_prm(a);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}