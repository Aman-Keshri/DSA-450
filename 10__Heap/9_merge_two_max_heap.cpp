/*

Input  :
n = 4 m = 3
a[] = {10, 5, 6, 2},
b[] = {12, 7, 9}
Output :
{12, 10, 9, 2, 5, 7, 6}

*/

class Solution
{
public:
    // Heapify Function
    //  Time  - O(logN) Space - O(1)
    void heapify(vector<int> &arr, int n, int i)
    {
        // set the given index as largest
        // find it's left and right index
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // check  for left and large index
        if (left < n && arr[large] < arr[left])
            large = left;

        // check for right index
        if (right < n && arr[large] < arr[right])
            large = right;

        // if the large has changed then swap value of given index and new large index
        //  and call heapify on the new index for further check
        if (large != i)
        {
            swap(arr[large], arr[i]);
            heapify(arr, n, large);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // step 1 merge both array
        vector<int> ans;
        for (auto i : a)
            ans.push_back(i);
        for (auto i : b)
            ans.push_back(i);

        // step 2 Build Max heap using heapify
        // build Max heap
        int size = ans.size();
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(ans, size, i);

        return ans;
    }
};