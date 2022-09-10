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

/*
balance BST means that
for every node the diffrence of height of two subtree is not more than 1

abs[height(left) - height(right)] <= 1
*/

pair<int, bool> balance(Node *root)
{
    if (root == NULL)
        return {0, true};

    pair<int, bool> lf = balance(root->left);
    pair<int, bool> rh = balance(root->right);

    pair<int, bool> a;
    if (abs(lf.first - rh.first) <= 1)
    {
        a.second = true;
    }
    else
        a.second = false;

    a.first = 1 + max(lf.first, rh.first);

    return a;
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    pair<int, bool> ans = balance(root);

    cout << "BST is balanced (0-false/ 1-true)   " << ans.second << endl;

    return 0;
}