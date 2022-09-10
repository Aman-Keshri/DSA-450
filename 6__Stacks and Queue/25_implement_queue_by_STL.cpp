#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main()
{
    queue<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.front() << endl;

    st.pop();

    cout << st.front() << endl;
    cout << st.empty();
    return 0;
}