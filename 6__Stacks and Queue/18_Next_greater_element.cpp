#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int element = arr[i];
        while (!st.empty() && st.top() < element)
            st.pop();

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(element);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = nextGreaterElement(arr);
    cout << "Answer is " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;
    return 0;
}