#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// moore's voting algorithm
void majorityElement(vector<int> &arr)
{
    int count = 0, element = 0;

    for (int num : arr)
    {
        if (count == 0)
            element = num;

        if (num == element)
            count++;
        else
            count--;
    }
    cout << "Majority Element is  " << element << endl;
}

int main()
{
    vector<int> arr = {4, 4, 1, 1, 1, 4, 4};
    majorityElement(arr);
    return 0;
}
