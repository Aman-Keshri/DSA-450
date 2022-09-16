/*
    Question - Given an array and an integer K,
    find the maximum for each and every contiguous subarray of size K

    Ans  -

*/

void printKMax(vector<int> arr, int n, int k)
{
    int j, maxi;

    for (int i = 0; i < n - k; i++)
    {
        maxi = arr[i];

        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > maxi)
                maxi = arr[j + i];
        }
        cout << maxi;
    }
}