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
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter node data :\n";
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter left data of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right data of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Levelorder traversal with endl after each level
void levelorder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

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

void buildtreefromLevelorder(Node *&root)
{
    queue<Node *> q;

    int data;
    cout << "Enter data for Root :\n";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int ldata, rdata;
        cout << "Enter left data of " << temp->data << endl;
        cin >> ldata;
        cout << "Enter right data of " << temp->data << endl;
        cin >> rdata;

        if (ldata != -1)
        {
            temp->left = new Node(ldata);
            q.push(temp->left);
        }

        if (rdata != -1)
        {
            temp->right = new Node(rdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // root = buildTree(root);
    root = PostbuildTree(root);
    // buildtreefromLevelorder(root);

    levelorder(root);

    return 0;
}