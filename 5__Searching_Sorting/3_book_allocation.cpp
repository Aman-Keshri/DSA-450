#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isallocation(vector<int> &arr, int cut, int student_count)
{
    int student = 1, page_count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > cut)
            return false;
        else if (arr[i] + page_count > cut)
        {
            student++;
            page_count = arr[i];
            if (page_count > cut)
                return false;
        }
        else
        {
            page_count += arr[i];
        }
    }
    if (student > student_count)
        return false;

    return true;
}

int allocate(vector<int> &arr, int student_count)
{
    int start = arr[0], end = 0;
    for (int i : arr)
    {
        end += i;
        start = min(start, arr[i]);
    }

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isallocation(arr, mid, student_count))
            end = mid - 1;
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    vector<int> ar = {10, 20, 30, 40};
    int student = 2;

    cout << "Min of Maxiumum pages is  " << allocate(ar, student) << endl;
    return 0;
}