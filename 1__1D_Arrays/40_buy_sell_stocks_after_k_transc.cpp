/*
From comments
Just like any other DP problem, we can start with a subproblem, and a subproblem here is determining the maximumProfit when k=1, k=2,... all the way to when k=k.

If we can do at most k transactions, it means that we can do (2 * k) operations .
For example,
For prices [3,2,6,5,0,3]
And for k = 2, we can perform only four operations (two buys and two sells) for maximum profit.

DRY RUN

Initial dp :            [-2147483648, -2147483648, -2147483648, -2147483648, -2147483648]
After first loop:       [ 0, -3, 0, -3, 0 ]
After second loop:      [ 0, -2, 0, -2, 0 ]
After third loop:       [ 0, -2, 4, -2, 4 ]
After forth loop:       [ 0, -2, 4, -1, 4 ]
After fifth loop:       [ 0,  0, 4,  4, 4 ]
After final  loop:      [ 0,  0, 4,  4, 7 ]

The Max val from the final dp table is 7, which is the answer.
Code

*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &price)
    {

        vector<int> dp(2 * k + 1, INT_MIN);
        dp[0] = 0;

        for (int j = 0; j < price.size(); j++)
        {

            for (int i = 0; i + 2 <= 2 * k; i += 2)
            {

                dp[i + 1] = max(dp[i + 1], dp[i] - price[j]);
                dp[i + 2] = max(dp[i + 2], dp[i + 1] + price[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};