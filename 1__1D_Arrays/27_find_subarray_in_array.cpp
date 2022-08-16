#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_prod(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    for (int i = 0; i < m; i++)
    {
        if (!st.count(b[i]))
            return 0;
    }
    return 1;
}

int main()
{
    vector<int> a = {2, 3, -2, 4};
    vector<int> b = {2, 5};
    if (max_prod(a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}