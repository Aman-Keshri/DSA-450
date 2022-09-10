#include <iostream>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

string firstNonrepeat(string A)
{
    unordered_map<char, int> mp;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // count store kro for that character
        mp[ch]++;

        // character ko push kro queue me
        q.push(ch);

        // jb tk > 1 occurence wala char pop kro
        //  agar nhi h answer me us char ko push kro or break out
        while (!q.empty())
        {
            if (mp[q.front()] > 1)
                q.pop();

            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        // loop se bahar do condtn me niklega
        // 1. agar repeating no nhi h
        // 2. rempeating numbers the or pop ho gaye
        // tb # dalna h
        if (q.empty())
            ans.push_back('#');
    }
    return ans;
}

int main()
{
    string a = "aabccbdd";
    string ans = firstNonrepeat(a);
    cout << "Answer is  " << ans << endl;
    return 0;
}