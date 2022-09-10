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

// time - O(N) space - O(N)/O(H)
Node *LCABST(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    if (root->data < p->data && root->data < q->data)
        return LCABST(root->right, p, q);

    if (root->data > p->data && root->data > q->data)
        return LCABST(root->left, p, q);

    else
        return root;
}

// time - O(N) space - O(1)
Node *LCABSTIterative(Node *root, Node *p, Node *q)
{
    while (root)
    {
        if (root->data < p->data && root->data < q->data)
            root = root->right;

        if (root->data > p->data && root->data > q->data)
            root = root->left;

        else
            return root;
    }
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    return 0;
}