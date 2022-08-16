#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int longest_sub(vector<int> &a)
{
    int n = a.size();
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    int longst = 0;

    for (int i = 0; i < n; i++)
    {
        if (!st.count(a[i] - 1))
        {
            int curnum = a[i];
            int cur_long = 1;

            while (st.count(curnum + 1))
            {
                curnum++;
                cur_long++;
            }
            longst = max(longst, cur_long);
        }
    }
    return longst;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longest_sub(a);
    cout << ans << endl;
    return 0;
}