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

int countleft(Node *leftNode)
{
    int h = 1;
    while (leftNode)
    {
        h++;
        leftNode = leftNode->left;
    }
    return h;
}

int countright(Node *rightNode)
{
    int h = 1;
    while (rightNode)
    {
        h++;
        rightNode = rightNode->right;
    }
    return h;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = countleft(root->left);
    int rh = countright(root->right);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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
    // root->left->left->left = newNode(8);
    // root->left->left->right = newNode(9);
    // root->right->right->right = newNode(10);

    int ans = countNodes(root);
    cout << (1 << 2) << endl;
    cout << "total nodes in Binary tree is - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}