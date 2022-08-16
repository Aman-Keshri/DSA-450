#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// using hashing
//  Time - O(2*N)  Space - O(N)
void repeatMissing(vector<int> &arr)
{
    vector<int> temp(arr.size() + 1, 0);
    int miss = 0, repeat = 0;
    for (int i = 0; i < arr.size(); i++)
        temp[arr[i]]++;

    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] > 1)
            repeat = i;

        if (temp[i] == 0)
            miss = i;
    }
    cout << "Repeat " << repeat << " mising " << miss << endl;
}

// using formula
/*
    LHS
        sum of n natural numbers - N(N+1)/2   - X
        sum of square of n natural numbers - N(N+1)(2N+1)/6    - X^2

    RHS
        sum of all elements of array    - Y
        sum of square of all elements of array    - Y^2

    X^2 - Y^2 = P
    X - Y = S

    X^2 - Y^2 =  P
    (X-Y) (X+Y) = S
    S (X+Y) = P
    X+Y = P/S

    X = P/S - Y  --->> {(S + P/S)/2}

    Y = X - S
*/
// Time - O(N)  space - O(1)
void repeatMissingI(const vector<int> &A)
{
    long long int len = A.size();

    long long int S = (len * (len + 1)) / 2;
    long long int P = (len * (len + 1) * (2 * len + 1)) / 6;

    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++)
    {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (S + P / S) / 2;

    repeating = missingNumber - S;

    cout << missingNumber << "  " << repeating << endl;
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    repeatMissingI(arr);
    return 0;
}