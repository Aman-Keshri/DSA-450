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

bool searchBST(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    if (root->data < target)
        return searchBST(root->right, target);

    else
        return searchBST(root->left, target);
}

bool searchBSTIterative(Node *root, int target)
{
    Node *temp = root;

    while (temp)
    {
        if (temp == NULL)
            return false;

        if (temp->data == target)
            return true;

        if (temp->data > target)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

int main()
{
    //[ 50, 30, 20, 40, 70, 60, 80, -1 ]
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);

    levelorder(root);

    bool ans = searchBST(root, 100);
    cout << "node found recursion (0-no / 1-yes)" << ans << endl;

    bool ans1 = searchBSTIterative(root, 100);
    cout << "node found iteration (0-no / 1-yes)" << ans1 << endl;
    return 0;
}