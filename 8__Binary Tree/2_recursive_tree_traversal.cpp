/*
recursive approach to tree traversal
pre, post and In order
*/

#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

void preorder(node * root) {
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node * root) {
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node * root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

struct node * newNode(int data) {
 struct node * tnode = (struct node *) malloc (sizeof(struct node));
 tnode->data = data;
 tnode->left=NULL;
 tnode->right=NULL;

 return(tnode);
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

    cout<<"1. Preorder - \n";
    preorder(root);
    cout<<"\n2. Postorder - \n";
    postorder(root);
    cout<<"\n3. Inorder - \n";
    inorder(root);
return 0;
}