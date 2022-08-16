#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    cout << "after removing part  " << removeOccurrences(s, part) << endl;
    return 0;
}