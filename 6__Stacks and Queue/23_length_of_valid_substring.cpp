#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

int lenvalidParanthesis(string str)
{
    stack<char> st;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (str[i] == '(')
            st.push(str[i]);

        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                count++;
            }
        }
    }
    int ans = count * 2;
    return ans;
}

int main()
{
    string str = "()))((";
    cout << str << endl;
    int ans = lenvalidParanthesis(str);
    cout << "length of valid pranthesis is " << ans << endl;
    return 0;
}