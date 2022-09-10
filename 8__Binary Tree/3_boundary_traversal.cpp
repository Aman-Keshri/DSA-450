#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node * left, * right;
};

struct node * newNode(int data)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool isleaf(node * root)
{
    return !root->left && !root->right;
}

void addleft(node * root, vector<int> & res)
{
    node * temp = root->left;
    while(temp)
    {
        if(!isleaf(temp))
            res.push_back(temp->data);
        
        if(temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
}

void addleaves(node * root, vector<int> & res)
{
    if(isleaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left) 
        addleaves(root->left, res);
    if(root->right) 
        addleaves(root->right, res);
}

void addright(node * root, vector<int> & res)
{
    node * temp = root->right;
    stack<int> s;
    while(temp)
    {
        if(!isleaf(temp))
            s.push(temp->data);
        if(temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}

vector<int> boundary(node * root)
{
    vector<int> res;

    if(root == NULL)
        return res;
    
    if(!isleaf(root))
        res.push_back(root->data);
    
    addleft(root, res);

    addleaves(root, res);
    
    addright(root, res);
    
    return res;
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

    vector<int> ans = boundary(root);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}