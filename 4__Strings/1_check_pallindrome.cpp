#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool valid_char(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

char tolower_char(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    else
    {
        char tm = ch - 'A' + 'a';
        return tm;
    }
}

bool checkpallindrome(string s)
{
    int st = 0, e = s.length() - 1;

    while (st < e)
    {
        if (s[st++] != s[e--])
            return false;
    }
    return true;
}

bool isPalindrome(string s)
{
    string temp = "";
    int j = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (valid_char(s[i]))
            temp.push_back(s[i]);
    }

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = tolower_char(temp[i]);
    }

    return checkpallindrome(temp);
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    if (isPalindrome(str))
        cout << "string is pallindrome\n";
    else
        cout << "string is not pallindrome\n";
    return 0;
}