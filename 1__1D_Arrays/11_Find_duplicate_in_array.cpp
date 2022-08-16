#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Time - O(N)  space - O(N)
void duplicate(vector<int> a)
{
    int n = a.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (auto i : mp)
    {
        if (i.second >= 2)
        {
            cout << i.second << endl;
            return;
        }
    }
    cout << "NA\n";
}

// Time - O(N)   space - O(1)
void duplicateI(vector<int> &a)
{
    int slow = a[0], fast = a[0];

    cout << "\nslow " << slow << " fast " << fast;
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
        cout << "\nslow " << slow << " fast " << fast;
    } while (slow != fast);

    fast = a[0];
    cout << "\nfast set to 0";

    while (slow != fast)
    {
        slow = a[slow];
        fast = a[fast];
        cout << "\nslow " << slow << " fast " << fast;
    }

    cout << "\nduplicate element is  " << slow << endl;
}

int main()
{
    vector<int> a = {1, 2, 3, 8, 7, 9, 10, 2};
    // duplicate(a);

    vector<int> ar = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    duplicateI(ar);
    return 0;
}