#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void common(vector<int> &a1, vector<int> &a2, vector<int> &a3)
{
    int n1 = a1.size();
    int n2 = a2.size();
    int n3 = a3.size();
    unordered_map<int, int> mp;
    vector<int> elements;
    for (int i = 0; i < n1; i++)
        mp[a1[i]]++;
    for (int i = 0; i < n2; i++)
        mp[a2[i]]++;
    for (int i = 0; i < n3; i++)
        mp[a3[i]]++;

    for (auto i : mp)
    {
        if (i.second % 3 == 0)
            elements.push_back(i.first);
    }
    for (int i = 0; i < elements.size(); i++)
        cout << elements[i] << " ";
}

int main()
{
    vector<int> a1 = {1, 5, 10, 20, 40, 80};
    vector<int> a2 = {6, 7, 20, 80, 100};
    vector<int> a3 = {3, 4, 15, 20, 30, 70, 80, 120};

    common(a1, a2, a3);
    return 0;
}