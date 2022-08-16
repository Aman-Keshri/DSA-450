#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void water(vector<int> &a)
{
    int n = a.size();
    int total = 0;
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = a[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], a[i]);

    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], a[i]);

    for (int i = 0; i < n; i++)
    {
        total += min(left[i], right[i]) - a[i];
    }
    cout << total << endl;
}

void waterOP(vector<int> a)
{
    int n = a.size();
    int left = 0, right = n - 1;
    int ans = 0;
    int leftmax = 0, rightmax = 0;

    while (left <= right)
    {
        if (a[left] <= a[right])
        {
            if (a[left] >= leftmax)
                leftmax = a[left];
            else
                ans += leftmax - a[left];

            left++;
        }
        else
        {
            if (a[right] >= rightmax)
                rightmax = a[right];
            else
                ans += rightmax - a[right];

            right--;
        }
    }

    cout << ans << endl;
}

int main()
{
    vector<int> a = {3, 1, 2, 4, 0, 1, 3, 2};
    water(a);
    waterOP(a);
    return 0;
}