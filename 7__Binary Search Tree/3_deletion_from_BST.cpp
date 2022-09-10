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
    vector<int> ans = {50, 20, 70, 10, 30, 90, 110, -1};

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

Node *minnode(Node *root)
{
    while (root->left)
        root = root->left;

    return root;
}

Node *deleteNode(Node *root, int val)
{
    // base case
    if (root == NULL)
        return root;

    // if value found in the node
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            // find the min from right subtree
            int mini = minnode(root->right)->data;

            // set the root to that min value
            root->data = mini;

            // now delete the min value from right subtree
            root->right = deleteNode(root->right, mini);

            return root;
        }
    }

    // if value is less than current node go left
    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }

    // if value is more than current node go right
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }

    return root;
}

int main()
{
    //{50, 20, 70, 10, 30, 90, 110, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);
    root = deleteNode(root, 20);
    levelorder(root);
    return 0;
}