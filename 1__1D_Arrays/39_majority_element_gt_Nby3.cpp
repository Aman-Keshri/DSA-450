#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// moore's voting algorithm
void majorityElement(vector<int> &arr)
{
    int count1 = 0, element1 = -1, count2 = 0, element2 = -1;
    int n = arr.size();

    /*
    for (int num : arr)
    {
        if (count == 0)
            element = num;

        if (num == element)
            count++;
        else
            count--;
    }
    */

    for (int num : arr)
    {
        if (num == element1)
            count1++;
        else if (num == element2)
            count2++;
        else if (count1 == 0)
        {
            element1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            element2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i : arr)
    {
        if (i == element1)
            count1++;
        if (i == element2)
            count2++;
    }

    if (count1 > n / 3)
        cout << element1 << " ";
    if (count2 > n / 3)
        cout << element2 << " \n";
}

int main()
{
    vector<int> arr = {4, 4, 1, 1, 2, 2, 2, 1, 4, 4};
    majorityElement(arr);
    return 0;
}
