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

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

// time - O(N)
info solve(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // recur on left and right part
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curNode;

    // checking for the current node once left and right are returned
    // update size as left + right + 1(current node)
    //  maximum will be max betwn current node and right maximum
    //  minimum will be min betwn current node and left minimum
    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = min(root->data, left.mini);

    // now to check for is BST
    // if left subtree and right subtree are BST
    // and also current node is greater than left's maxi and current node is less than right mini
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        curNode.isBST = true;
    }
    else
    {
        curNode.isBST = false;
    }

    // if the current node is BST update the ans with max betwn current ans and size of curnode
    if (curNode.isBST)
        ans = max(ans, curNode.size);

    return curNode;
}

int largestBST(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);

    return maxSize;
}

int main()
{
    struct Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    int ans = largestBST(root);

    cout << "Count of BST in Binary tree is - " << ans << "\n";

    return 0;
}