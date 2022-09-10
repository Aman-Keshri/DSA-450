#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inserttoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = inserttoBST(root->right, d);
    else
        root->left = inserttoBST(root->left, d);

    return root;
}

void takeInput(Node *&root)
{
    vector<int> ans = {50, 30, 20, 40, 70, 60, 80, -1};

    for (auto data : ans)
    {
        if (data != -1)
            inserttoBST(root, data);
    }
}

void levelorder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    cout << "Level Order\n";
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(Node *root, vector<int> &inord)
{
    if (root == NULL)
        return;

    inorder(root->left, inord);
    inord.push_back(root->data);
    inorder(root->right, inord);
}

Node *flatten(Node *root)
{
    if (root == NULL)
        return NULL;

    // step 1 store the inorder of BST
    vector<int> inord;
    inorder(root, inord);
    int n = inord.size();

    // step 2 create new node and point its left to NULL and right to next node

    // kepp cur node to 1st element
    Node *newRoot = new Node(inord[0]);
    Node *cur = newRoot;

    // loop from 2nd element and create new node poin the cur to temp(new node) then increment cur to temp and create new node
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(inord[i]);
        cur->left = NULL;
        cur->right = temp;
        cur = temp;
    }
    // step 3 for the last node point left to NULL and right to NULL
    cur->left = NULL;
    cur->right = NULL;

    return newRoot;
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    Node *ans = flatten(root);
    cout << "flat BST is \n";
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->right;
    }
    return 0;
}