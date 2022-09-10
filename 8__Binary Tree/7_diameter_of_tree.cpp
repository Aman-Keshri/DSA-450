#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

int cal_diameter(node *curr, int diameter)
{
    if (curr == NULL)
        return 0;

    int lh = cal_diameter(curr->left, diameter);
    int rh = cal_diameter(curr->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    int diameter = 0;
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // root -> left -> right -> left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // root -> right -> right -> left = newNode(9);
    // root -> right -> right -> right = newNode(10);

    int dia = cal_diameter(root, diameter);

    cout << dia;

    return 0;
}