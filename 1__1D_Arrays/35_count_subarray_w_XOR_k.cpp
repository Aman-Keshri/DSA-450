#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// Time - O(N)  space - O(N)
void subarraywithXOR(vector<int> &ar, int k)
{
    int XOR = 0, count = 0;
    unordered_map<int, int> mp;

    for (int it : ar)
    {
        XOR ^= it;

        if (XOR == k)
            count++;

        if (mp.find(XOR ^ k) != mp.end())
        {
            count += mp[XOR ^ k];
        }
        mp[XOR]++;
    }

    cout << "Total Subarray with given XOR is  " << count << endl;
}

int main()
{
    vector<int> ar = {4, 2, 2, 6, 4};
    int k = 6;
    subarraywithXOR(ar, k);
    return 0;
}