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

bool solve(Node *left, Node *right)
{
    // both left and right have to be null
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return solve(left->right, right->left) && solve(left->left, right->right);
}

bool isSymmetric(Node *root)
{
    return (root == NULL || solve(root->left, root->right));
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    bool ans = isSymmetric(root);

    cout << "Binary tree is Symmetric(0-false/1-true) - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}