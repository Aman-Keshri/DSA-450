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

int findlargestsubtreesum(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    // Subtree sum rooted at current node.
    int curSum = root->data + findlargestsubtreesum(root->left, ans) + findlargestsubtreesum(root->right, ans);

    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, curSum);

    // Return current subtree sum to
    // its parent node.
    return curSum;
}

int largestsubtree(Node *root)
{
    if (root == NULL)
        return 0;

    // Variable to store maximum subtree sum.
    int ans = INT_MIN;

    // Call to recursive function to
    // find maximum subtree sum.
    findlargestsubtreesum(root, ans);
    return ans;
}

int main()
{

    // struct Node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    struct Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    int ans = largestsubtree(root);

    cout << "Max Height of Binary tree is - " << ans << "\n";

    return 0;
}