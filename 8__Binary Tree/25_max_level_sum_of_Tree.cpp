#include <bits/stdc++.h>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return -1;

        long long int mxSum = INT_MIN;
        int lvl = 0, mxlvl = 0;
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            long long int sum = 0;
            lvl++;
            while (size--)
            {
                TreeNode *frontNode = q.front();
                q.pop();

                sum += frontNode->val;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }
            if (sum > mxSum)
            {
                mxSum = sum;
                mxlvl = lvl;
            }
        }
        return mxlvl;
    }
};