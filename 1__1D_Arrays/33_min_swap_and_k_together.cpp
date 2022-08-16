#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void small_array(vector<int> &a, int in1)
{
    int n = a.size(), sw = 0;
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (a[left] < in1)
            left++;
        else if (a[right] > in1)
            right--;
        else
        {
            sw++;
            swap(a[left], a[right]);
        }
    }
    cout << sw;
}

int main()
{
    vector<int> a = {2, 7, 9, 5, 8, 7, 4};
    int in1 = 6;
    small_array(a, in1);
    return 0;
}