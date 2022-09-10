#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int firstNegative(long long int arr[], long long int n, long long int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);
    int ans = 0;

    // addition of first k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // at first the sum of first window is added
    ans += arr[maxi.front()] + arr[mini.front()];

    // loop for remaining k size window

    for (int i = k; i < n; i++)
    {

        // remove the elements not in window size
        while (!maxi.empty() && (i - maxi.front()) >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && (i - mini.front()) >= k)
        {
            mini.pop_front();
        }

        // add the elements that will be considered in window
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        // add the max and min to sum
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main()
{
    long long int arr[] = {2, 5, -1, 7, -3, -1, -2};
    long long int size = 7;
    long long int k = 4;

    int ans = firstNegative(arr, size, k);

    cout << "ANswer is  " << ans << endl;

    return 0;
}