#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

// Time - 2*O(N)  Space - 3*O(N)
int largestRectangleArea(vector<int> &arr)
{
    int len = arr.size();
    int leftmin[len], rightmin[len];
    stack<int> st;
    int MaxA = 0;

    // left minimum
    for (int i = 0; i < len; i++)
    {
        // first remove all elements greater than current element
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        // assign value to leftmin array
        // if stack is empty that means Minimum will be first index
        if (st.empty())
            leftmin[i] = 0;
        // else minimum will the element next to the element at top of stack
        else
            leftmin[i] = st.top() + 1;
        // push the index of the curent element to stack
        st.push(i);
    }

    // similarly for right minimum
    // left minimum
    for (int i = len - 1; i >= 0; i--)
    {
        // first remove all elements greater than current element
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        // assign value to leftmin array
        // if stack is empty that means Minimum will be first index
        if (st.empty())
            rightmin[i] = len - 1;
        // else minimum will the element next to the element at top of stack
        else
            rightmin[i] = st.top() - 1;
        // push the index of the curent element to stack
        st.push(i);
    }

    // using the formula find the area and store the largest among them
    for (int i = 0; i < len; i++)
    {
        cout << "left  " << leftmin[i] << "  right  " << rightmin[i] << endl;
        int area = arr[i] * (rightmin[i] - leftmin[i] + 1);
        MaxA = max(MaxA, area);
    }

    return MaxA;
}

// Time - O(N)  Space - O(N)
int largestRectangleAreaI(vector<int> &arr)
{
    int len = arr.size();
    stack<int> st;
    int MaxA = 0;

    for (int i = 0; i <= len; i++)
    {
        while (!st.empty() && (i == len || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            cout << "\nh  " << height << "  w  " << width << "  s top  " << st.top() << " i " << i;
            MaxA = max(MaxA, (height * width));
        }
        st.push(i);
    }
    return MaxA;
}

// practice
int largestAreaHistogram(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    int area = 0;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
        {
            int height = arr[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            area = max(area, (height * width));
        }
        st.push(i);
    }
    return area;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int ans = largestAreaHistogram(arr);
    cout << "Answer is " << ans << endl;
    return 0;
}