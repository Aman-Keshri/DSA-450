#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    int n = s.length();
    int st = 0, en = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            en = i - 1;
            while (st < en)
            {
                swap(s[st], s[en]);
                st++;
                en--;
            }

            st = i + 1;
            en = i;
        }
        else
            en++;
    }
    return s;
}

int main()
{
    string str = "Hello from Aman Keshri";
    string s = rev(str);
    cout << s;
    return 0;
}