#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void deleteMid(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        cout << "deleting mid" << endl;
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();
    deleteMid(st, count + 1, size);
    cout << "add ele before mid" << endl;
    st.push(num);
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
    int count = 0;
    int size = st.size();
    deleteMid(st, count, size);
    cout << st.top() << endl;
    return 0;
}