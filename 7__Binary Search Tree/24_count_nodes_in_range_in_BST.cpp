class Solution
{
public:
    int solve(Node *root, int l, int h, int &count)
    {
        if (root == NULL)
            return 0;

        if (root->data >= l && root->data <= h)
            count++;

        solve(root->left, l, h, count);
        solve(root->right, l, h, count);

        return count;
    }

    int getCount(Node *root, int l, int h)
    {
        // your code goes here
        int count = 0;

        return solve(root, l, h, count);
    }
};