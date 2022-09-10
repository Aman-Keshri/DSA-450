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

void solve(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
        return;

    path.push_back(root->data);

    // go left
    solve(root->left, k, count, path);
    // go right
    solve(root->right, k, count, path);

    // check for K sum
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);

    return count;
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(2);
    root->right = newNode(-1);
    root->right->left = newNode(3);
    root->right->left->left = newNode(2);
    root->right->left->right = newNode(5);

    int ans = sumK(root, 3);

    cout << "No of paths with sum is - " << ans << "\n";

    // vector<int> ans = sumK(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}