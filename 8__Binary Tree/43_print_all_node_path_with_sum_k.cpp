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

void printpath(vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void solve(Node *root, int target, vector<int> &ans)
{
    // if root null i.e notfound target yet but reached leaf node
    if (root == NULL)
        return;

    // store node in vector
    ans.push_back(root->data);

    // recurse on left and right subtree of the node
    solve(root->left, target, ans);

    solve(root->right, target, ans);

    int sum = 0;
    for (int j = ans.size() - 1; j >= 0; j--)
    {
        sum += ans[j];

        if (sum == target)
            printpath(ans, j);
    }

    // if not found target in left and right part pop the node out of vector
    ans.pop_back();
}

void roottonode(Node *root, int target)
{
    vector<int> ans;
    if (root == NULL)
        return;

    solve(root, target, ans);
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);

    // int ans = function(root);

    // cout << "Max Height of Binary tree is - " << ans << "\n";

    roottonode(root, 5);

    return 0;
}