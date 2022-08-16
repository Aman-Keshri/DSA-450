#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void small_array(vector<int> &a, int in1, int in2)
{
    int n = a.size();
    int left = 0, right = n - 1;
    for (int i = 0; i <= right; i++)
    {
        // cout << " a[i] " << a[i] << " left " << a[left] << " right " << a[right] << endl;
        if (a[i] < in1)
        {
            swap(a[i], a[left]);
            left++;
        }
        else if (a[i] > in2)
        {
            swap(a[i], a[right]);
            right--;
            i--;
        }

        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> a = {6, 9, 11, 3, 8, 5, 19, 21};
    int in1 = 7, in2 = 12;
    small_array(a, in1, in2);
    // TWP(a, in1, in2);
    return 0;
}