#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void insertAsc(stack<int> &s, int element)
{
    if (s.empty() || (!s.empty() && s.top() < element))
    {
        cout << "no element left so add" << endl;
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertAsc(s, element);
    cout << "add ele to correct position" << endl;
    s.push(num);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int num = st.top();
    st.pop();
    sortStack(st);
    cout << "insert in sorted way" << endl;
    insertAsc(st, num);
}

int main()
{
    stack<int> st;
    st.push(9);
    st.push(2);
    st.push(6);
    st.push(4);
    st.push(1);
    cout << st.top() << endl;
    sortStack(st);
    cout << st.top() << endl;
    return 0;
}