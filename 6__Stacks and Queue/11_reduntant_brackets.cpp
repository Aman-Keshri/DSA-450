#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

bool checkValid(char tp)
{
    if (tp == '+' || tp == '-' || tp == '*' || tp == '/')
        return true;
    else
        return false;
}

bool matches(stack<char> &st, char ch)
{
    char tp = st.top();
    if (checkValid(tp))
    {
        while (checkValid(tp))
        {
            st.pop();
            tp = st.top();
        }
        if ((tp == '[' && ch == ']') || (tp == '{' && ch == '}') || (tp == '(' && ch == ')'))
            return true;
        else
            return false;
    }
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
        if (ch == '[' || ch == '{' || ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(str[i]);
            cout << st.top() << " -> ";
        }

        else if (ch == ']' || ch == '}' || ch == ')')
        {
            if (!st.empty())
            {
                if (matches(st, ch))
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

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch ya toh ')' hai or lowercase letter

            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string str = "[a+b*{(c/t)+(+)}]";
    cout << str << endl;
    bool flag = validParanthesis(str);
    if (flag == true)
        cout << "\nBalanced\n";
    else
        cout << "\nNot Balanced\n";
    return 0;
}