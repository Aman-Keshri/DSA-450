#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int sqrtroot(int key)
{
    int start = 0;
    int end = key;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int square = mid * mid;
        if (square == key)
            return mid;

        if (square < key)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return ans;
}

double precision(int n, int precise, int soln)
{
    double factor = 1;
    double ans = -1;

    for (int i = 0; i < precise; i++)
    {
        factor /= 10;
        for (double j = soln; j * j <= n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int key = 40;
    int soln = sqrtroot(key);
    cout << "square root is  " << soln << endl;
    cout << "precise root is " << precision(key, 3, soln) << endl;
    return 0;
}