#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void power(int n, double x)
{
    double ans = 1.0;
    long long nn = n;

    if (nn < 0)
        nn = -1 * nn;

    while (nn)
    {
        if (nn % 2)
        {
            ans *= x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn /= 2;
        }
    }

    if (n < 0)
        ans = (double)(1.0) / (double)(ans);

    cout << "Power is  " << ans;
}

int main()
{
    int n = 10;
    double x = 2;
    power(n, x);
    return 0;
}