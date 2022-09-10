/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    int countPairs(Node *root1, Node *root2, int x)
    {
        if (root1 == NULL || root2 == NULL)
            return -1;

        vector<int> r1;
        vector<int> r2;
        int count = 0;

        inorder(root1, r1);
        inorder(root2, r2);

        int i = 0, j = r2.size() - 1;
        while (i < r1.size() && j >= 0)
        {
            int sum = r1[i] + r2[j];

            if (sum == x)
                count++;

            if (sum < x)
                i++;
            else
                j--;
        }

        return count;
    }
};