#include<bits/stdc++.h>
using namespace std;

struct node {
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

vector<vector<int>> zigzag(node * root)
{
    vector<vector<int>> ans;

    if( root== NULL)
        return ans;

    queue<node *> q;

    q.push(root);
    bool lefttoright = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++)
        {
            node * temp = q.front();
            q.pop();

            int index = (lefttoright) ? i : (size-i-1);
            row[index] = temp->data;

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

        lefttoright = !lefttoright;
        ans.push_back(row);
    }
    return ans;
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

    vector<vector<int>> result = zigzag(root);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}