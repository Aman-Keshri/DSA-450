#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

int *stockspan(int *price, int n)
{
    int *S = new int[n];

    stack<int> st;
    st.push(0);
    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && price[st.top()] < price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return S;
}

int main()
{
    int arr[7] = {100, 80, 60, 70, 60, 75, 85};
    int ar[7] = {10, 10, 10, 10, 10, 10, 10};
    int ar1[8] = {60, 70, 80, 100, 90, 75, 80, 120};
    int *ans = stockspan(arr, 8);
    cout << "Answer is " << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;
    return 0;
}