/*
Input:
n = 4
arr[] = {4, 3, 2, 6}
Output:
29
Explanation:
For example if we are given 4
ropes of lengths 4, 3, 2 and 6. We can
connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Now we have three ropes of lengths 4, 6
and 5.
2) Now connect ropes of lengths 4 and 5.
Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all
ropes have connected.
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. Other ways of
connecting ropes would always have same
or more cost. For example, if we connect
4 and 6 first (we get three strings of 3,
2 and 10), then connect 10 and 3 (we get
two strings of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.

*/

#include <queue>

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    // TIme - O(NlogN)  Space - O(N)
    long long minCost(long long arr[], long long n)
    {
        // Your code here

        // step 1 create MIN heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++)
            pq.push(arr[i]);

        long long ans = 0;

        /*
            step 2 extract top 2 elements from MIN Heap
            step 3 find there sum and push sum back to MIN Heap
            step 4 add the sum to ans
            step 5 return ans
        */
        // loop until heap has only 1 element
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = a + b;
            ans += sum;

            pq.push(sum);
        }

        return ans;
    }
};