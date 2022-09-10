#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void insertatBottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        cout << "adding at last" << endl;
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertatBottom(s, element);
    cout << "add ele before last" << endl;
    s.push(num);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    insertatBottom(st, 10);
    cout << st.top() << endl;
    return 0;
}