#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node * left, * right;
};

struct node* newNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp ->data = data;
    temp->right = NULL;
    temp->left = NULL;
}

bool issametree(node * root, node * root1)
{
    if(root == NULL && root1 == NULL) 
        return true;   

    else if(root == NULL || root1 == NULL)
        return false;

    return ((root->data == root1->data) && issametree(root->left, root1->left) && issametree(root->right, root1->right));
}

int main()
{
    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);

    struct node * root1 = newNode(1);
    root1 -> left = newNode(2);
    root1 -> right = newNode(3);
    root1 -> left -> left = newNode(4);
    root1 -> left -> right = newNode(5);
    root1 -> left -> right -> left = newNode(8);
    root1 -> right -> left = newNode(6);
    root1 -> right -> right = newNode(7);
    root1 -> right -> right -> left = newNode(9);
    root1 -> right -> right -> right = newNode(10);

    if(issametree(root, root1))
        cout<<"identical";
    else
        cout<<"not";
    return 0;
}