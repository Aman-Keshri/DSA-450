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

void takeInput(Node *&root, vector<int> ans)
{
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

// time - O(log N)
int floorBST(Node *root, int key)
{
    if (root == NULL)
        return -1;

    int flr = -1;

    while (root)
    {
        if (root->data == key)
        {
            flr = root->data;
            return flr;
        }

        if (key > root->data)
        {
            // updating the curr before moving left as me need lower value so the can be lower value.
            flr = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return flr;
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;
    vector<int> order = {50, 30, 20, 40, 70, 60, 80, -1};
    cout << "Enter data to create BST tree\n";
    takeInput(root, order);
    levelorder(root);

    cout << "Ans is  " << floorBST(root, 65) << endl;

    return 0;
}