#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2 == 1)
        return -1;

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (str[i] == '{')
            st.push(str[i]);

        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
            a++;
        else
            b++;

        st.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str = "{{}}}}";
    cout << str << endl;
    int ans = findMinimumCost(str);
    cout << "Minimum cost to make valid is " << ans << endl;
    return 0;
}