#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &ar, int th, int divisor)
{
    int sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] % divisor)
            sum += (ar[i] / divisor) + 1;
        else
            sum += (ar[i] / divisor);
    }
    return (sum <= th) ? true : false;
}

int smalldivisor(vector<int> &ar, int th)
{
    int maxi = INT32_MIN, mini = 1;

    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] >= maxi)
            maxi = ar[i];
    }
    int mid = -1, ans = -1;
    while (mini <= maxi)
    {
        mid = mini + (maxi - mini) / 2;

        if (ispossible(ar, th, mid))
        {
            ans = mid;
            maxi = mid - 1;
        }
        else
            mini = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 3, 5, 7, 11};
    int th = 11;
    cout << "smallest divisor is  " << smalldivisor(a, th) << endl;
    return 0;
}