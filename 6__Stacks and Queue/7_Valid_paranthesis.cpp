#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

bool matches(char tp, char ch)
{
    cout << tp << " top  str[i] " << ch << endl;
    if ((tp == '[' && ch == ']') || (tp == '{' && ch == '}') || (tp == '(' && ch == ')'))
        return true;
    else
        return false;
}

bool validParanthesis(string str)
{
    stack<char> st;
    bool flag = true;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
            st.push(str[i]);

        else
        {
            if (!st.empty())
            {
                char tp = st.top();
                if (matches(tp, ch))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string str = "[{()}]";
    cout << str << endl;
    bool flag = validParanthesis(str);
    if (flag == true)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}