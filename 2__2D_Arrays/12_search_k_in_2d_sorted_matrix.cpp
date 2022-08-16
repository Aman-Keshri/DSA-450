#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int lr = 0, lc = 0, hr = matrix.size() - 1, hc = matrix[0].size() - 1, mr;
    while (lr <= hr)
    {
        mr = (lr + hr) / 2;
        if (target >= matrix[mr][lc] && target <= matrix[mr][hc])
        {
            for (int j = lc; j <= hc; j++)
            {
                if (matrix[mr][j] == target)
                    return true;
            }
            return false;
        }
        else if (target < matrix[mr][lc])
            hr = mr - 1;
        else
            lr = mr + 1;
    }
    return false;
}

bool find_k(vector<vector<int>> &arr, int target)
{
    int low_row = 0, high_row = arr.size() - 1;
    int low_col = 0, high_col = arr[0].size() - 1;
    int mid_row, mid_col;

    // Binary search to find the correct row to search the number
    while (low_row < high_row)
    {
        mid_row = (low_row + high_row) / 2;

        // check if the target number is present in the row or not
        if (target >= arr[mid_row][low_col] && target <= arr[mid_row][high_col])
        {
            // Binary search to find the target within the row
            while (low_col < high_col)
            {
                mid_col = (low_col + high_col) / 2;

                // normal binary search if mid == to target
                if (arr[mid_row][mid_col] == target)
                    return true;

                // if mid > target move left
                else if (arr[mid_row][mid_col] > target)
                    high_col = mid_col - 1;

                // if mid < target move right
                else
                    low_col = mid_col + 1;
            }
            return false;
        }

        // check if target is greater than last element of row then move right
        else if (arr[mid_row][high_col] < target)
            low_row = mid_row + 1;

        // move left
        else
            high_col = mid_row - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    int target = 11;
    bool ans = find_k(arr, target);
    if (ans)
        cout << "Yes k is present \n";
    else
        cout << "No k is not present \n";
    return 0;
}