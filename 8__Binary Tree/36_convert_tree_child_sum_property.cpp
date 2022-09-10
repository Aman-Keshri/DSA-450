#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void reorder(node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    // if root has left and right add them
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    // if the addition is greater than root itself then assign sum to root
    if (child >= root->data)
        root->data = child;

    // else if not greater
    // assign the left and right to element a root
    else
    {
        if (root->left)
            root->left->data = root->data;

        if (root->right)
            root->right->data = root->data;
    }

    // recur to keft and right subtree
    reorder(root->left);
    reorder(root->right);

    // while returning back from left and right
    // add left and right and assign it to root node
    // it should be leaf node as in case of leaf node the root will remain the same
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;

    if (root->left || root->right)
        root->data = total;
}

void changeTree(node *root)
{
    reorder(root);
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node *root = newNode(2);
    root->left = newNode(35);
    root->left->left = newNode(2);
    root->left->right = newNode(3);
    root->right = newNode(10);
    root->right->left = newNode(5);
    root->right->right = newNode(2);

    changeTree(root);

    return 0;
}