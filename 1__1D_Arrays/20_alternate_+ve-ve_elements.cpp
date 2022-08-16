#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void alternate(vector<int> a)
{
    int n = a.size();
    int pivot = -1, i = 0;
    while (i < n)
    {
        if (a[i] < 0)
        {
            pivot++;
            swap(a[pivot], a[i]);
        }
        i++;
    }
    int neg = 0, pos = pivot + 1;
    while (neg < pos && pos < n && a[neg] < 0)
    {
        swap(a[neg], a[pos]);
        neg += 2;
        pos++;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    vector<int> a = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    alternate(a);
    return 0;
}