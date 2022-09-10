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

bool solve(Node *root, int target, vector<int> &ans)
{
    // if root null i.e notfound target yet but reached leaf node
    if (root == NULL)
        return false;

    // store node in vector
    ans.push_back(root->data);

    // check if it is the target node
    if (root->data == target)
        return true;

    // if not the target node recurse on left and right subtree of the node
    if (solve(root->left, target, ans) || solve(root->right, target, ans))
        return true;

    // if not found target in left and right part pop the node out of vector
    ans.pop_back();

    // and return false
    return false;
}

vector<int> roottonode(Node *root, int target)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    solve(root, target, ans);

    return ans;
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
    root->left->right->left = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    // int ans = function(root);

    // cout << "Max Height of Binary tree is - " << ans << "\n";

    vector<int> ans = roottonode(root, 9);

    for (auto i : ans)
        cout << i << "  ";

    return 0;
}