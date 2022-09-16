/*
    Approach 1
    Time - O(N^2 Log N)  Space - O(N^2)

    Idea is to store sum of all sub array in vector and the nsort and find kth largest
    step 1 nested loop to find sum of each subarray and store in vector
    step 2 sort the new vector
    step 3 return size - k th index element as ans;
*/
#include <algorithm>

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum;
    vector<int> result;

    // step 1
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            result.push_back(sum);
        }
    }

    // step 2
    sort(result.begin(), result.end());

    // step 3
    return result[result.size() - k];
}

/*
Approach 2
Using MIN HEAP
Time - O(N^2)  Space - O(K)

step 1 create min heap of k elements
step 2 then loop to find subarray sum
step 3 if min heap size less than k the push else min heap top < curr sum then pop top and insert sum

*/
#include <queue>

int getKthLargest(vector<int> &arr, int k)
{
    // step 1
    priority_queue<int, vector<int>, greater<int>> pq;

    // step 2
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
                pq.push(sum);
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}