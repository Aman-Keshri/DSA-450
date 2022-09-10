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

pair<bool, int> isSumTreeCheck(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTreeCheck(root->left);
    pair<bool, int> right = isSumTreeCheck(root->right);

    bool condn = (root->data == (left.second + right.second));

    pair<bool, int> ans;
    if (left.first && right.first && condn)
    {
        ans.first = true;
        ans.second = 2 * (root->data);
    }
    else
    {
        ans.first = false;
        ans.second = -1;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    return isSumTreeCheck(root).first;
}

int main()
{
    struct Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    // struct Node *root = newNode(20);
    //  root->left = newNode(10);
    //  root->right = newNode(10);
    //  root->left->left = newNode(4);
    //  root->left->right = newNode(6);
    //  root->left->right->left = newNode(8);
    //  root->right->left = newNode(3);
    //  root->right->right = newNode(7);
    //  root->right->right->left = newNode(9);
    //  root->right->right->right = newNode(10);

    bool ans = isSumTree(root);

    cout << "Sum of Binary tree is(0-false / 1-true) - " << ans << "\n";

    return 0;
}