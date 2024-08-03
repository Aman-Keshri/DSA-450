class Solution
{

private:
    void recursePermute(vector<int> &nums, vector<vector<int>> &ans,
                        vector<int> ds, int freq[])
    {
        // base case
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        // loop on each element of array and check
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[i] == 0)
            {
                ds.push_back(nums[i]);
                freq[i] = 1;

                recursePermute(nums, ans, ds, freq);

                ds.pop_back();
                freq[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        // declare ans  vector, map, and a data structure to store ans
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];

        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;

        recursePermute(nums, ans, ds, freq);

        return ans;
    }
};

// Time - O(N!) * N
// Space - O(N) + O(N)

//***************************************************************************
// Approach 2

class Solution
{

private:
    void recursePermute(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        // base case
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // loop on each element of array and check
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            recursePermute(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        // declare ans  vector to store ans
        vector<vector<int>> ans;

        recursePermute(0, nums, ans);

        return ans;
    }
};

// Time - O(N!) * N
// Space - O(1)
