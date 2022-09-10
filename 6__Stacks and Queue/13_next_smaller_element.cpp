#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        while (!st.empty() && st.top() > element)
            st.pop();

        ans[i] = st.top();
        st.push(element);
    }
    return ans;
}

int main()
{
    vector<int> arr = {8, 2, 1, 4, 3, 0};
    vector<int> ans = nextSmallerElement(arr);
    cout << "Answer is " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;
    return 0;
}