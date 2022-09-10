#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

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
            // cout << "\nh  " << height << "  w  " << width << "  s top  " << st.top() << " i " << i;
            MaxA = max(MaxA, (height * width));
        }
        st.push(i);
    }
    return MaxA;
}

void largestRectangle(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    int Maxi = 0, cur_area = 0;
    vector<int> temp(col, 0);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // if cell has 1 add 1 to the coresponding temp array
            if (arr[i][j] != 0)
                temp[j] += arr[i][j];
            // if cell has 0 reset the height to 0
            else
                temp[j] = 0;
        }
        // call the largest area histogram function on the temp array
        cur_area = largestRectangleAreaI(temp);

        // take largest area.
        Maxi = max(Maxi, cur_area);
    }
    cout << "Max area of rectangle is  " << Maxi << endl;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 1, 0, 0},
                               {1, 0, 1, 1, 1},
                               {1, 1, 1, 1, 1},
                               {1, 0, 0, 1, 0}};
    largestRectangle(arr);
    return 0;
}