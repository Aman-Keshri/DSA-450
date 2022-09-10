#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftans = solve(root->left);
    pair<int, int> rightans = solve(root->right);

    pair<int, int> res;
    // first  - max sum including nodes at current level
    // sum of current node + exclude of left and exclude of right
    res.first = root->data + leftans.second + rightans.second;
    // second - max sum excluding nodes at current level
    // sum of max of left and right pair
    res.second = max(leftans.first, leftans.second) + max(rightans.first, rightans.second);

    return res;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);

    // first  - max sum including nodes at current level
    // second - max sum excluding nodes at current level
    return max(ans.first, ans.second);
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    int ans = getMaxSum(root);

    cout << "Max Height of Binary tree is - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}