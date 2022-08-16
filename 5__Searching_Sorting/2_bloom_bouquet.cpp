#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &ar, int days, int boq, int flwr)
{
    int flwr_count = flwr;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] <= days)
        {
            flwr_count--;
        }
        else
            flwr_count = flwr;

        if (flwr_count == 0)
        {
            boq--;
            if (boq == 0)
                return true;

            flwr_count = flwr;
        }
    }
    return false;
}

int bloomday(vector<int> &ar, int boq, int flwr)
{
    int n = ar.size();
    int mini = INT32_MAX, maxi = INT32_MIN;
    if (boq * flwr > n)
        return -1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (ar[i] > maxi)
                maxi = ar[i];

            if (ar[i] < mini)
                mini = ar[i];
        }

        while (mini <= maxi)
        {
            int mid = mini + (maxi - mini) / 2;

            if (ispossible(ar, mid, boq, flwr))
                maxi = mid - 1;
            else
                mini = mid + 1;
        }

        return mini;
    }
}

int main()
{
    vector<int> a = {7, 7, 7, 7, 12, 7, 7};
    int bq = 2, fl = 3;
    cout << "min days for flower  " << bloomday(a, bq, fl) << endl;
    return 0;
}