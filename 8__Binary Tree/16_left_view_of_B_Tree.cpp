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

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    // this is a logic to check that for each level onl one node is pushed
    //  level 0 - size of ans is 0 so push
    //  level 1 - size will be 1 as 1 element will be pushed from level 0
    //  level 2 - size will be 2 as 1 more element will be pushed from level 1 ans so on...
    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftview(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    solve(root, ans, 0);
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

    vector<int> ans = leftview(root);

    for (auto i : ans)
        cout << i << "  ";

    return 0;
}