#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void ReverseStringbyStack(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
        st.push(str[i]);

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    string str = "AmanKeshri";
    ReverseStringbyStack(str);

    return 0;
}