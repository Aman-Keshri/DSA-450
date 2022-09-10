#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node * left, * right;
};

int dfsheight(struct node * root)
{
    if(root == NULL) return 0;

    int left = dfsheight(root->left);
    if(left == -1) return -1;

    int right = dfsheight(root->right);
    if(right == -1) return -1;

    if((abs(left) - right) > 1) return -1;
    return max(left,right) + 1;
}

bool isbalance(struct node * root)
{
    return dfsheight(root) != -1;
}

struct node * newNode(int data)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

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

    bool balanced = isbalance(root);

    cout<<balanced;
    return 0;
}
