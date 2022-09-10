#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> firstNegative(long long int A[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process
    for (int i = 0; i < k; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store ans of first k size window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remainming window
    for (int i = k; i < n; i++)
    {
        // removal from dq
        if (!dq.empty() && i - dq.front() >= k)
            dq.pop_front();

        // addtion to dq
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

// to be studied later
void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;

    for (int i = k - 1; i < n; i++)
    {

        // skip out of window and positive elements
        while ((firstNegativeIndex < i) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }

        // check if a negative element is found, otherwise
        // use 0
        if (arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }
}

int main()
{
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int size = 5;
    long long int k = 2;

    vector<long long> ans = firstNegative(arr, size, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}