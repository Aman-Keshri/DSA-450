#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool check_palin(int num)
{
    int rev = 0, temp;
    temp = num;
    while (num)
    {
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }
    if (rev == temp)
        return true;
    else
        return false;
}

bool palindrome(vector<int> &a)
{
    int n = a.size(), sw = 0;

    for (int i = 0; i < n; i++)
    {
        if (!check_palin(a[i]))
            return false;
    }
    return true;
}

int main()
{
    vector<int> a = {111, 2872, 333, 444, 555};
    if (palindrome(a))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}