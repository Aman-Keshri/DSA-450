#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &a1, vector<int> &a2)
{
    if (a2.size() < a1.size())
        return median(a2, a1);

    int n1 = a1.size(), n2 = a2.size();
    int low = 0, high = n1;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : a1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : a2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : a1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : a2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> a1 = {7, 12, 14, 15, 16};
    vector<int> a2 = {1, 2, 3, 4, 9, 11};
    cout << median(a1, a2);
    return 0;
}