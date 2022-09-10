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

bool targetSum(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
        return root->data == target;

    bool leftans = targetSum(root->left, target - root->data);
    bool rightans = targetSum(root->right, target - root->data);

    return (leftans || rightans);
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

    bool ans = targetSum(root, 15);

    cout << "Target Sum found in Binary tree (0-false/1-true) - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}