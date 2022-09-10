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

// preorder se check kiya
int count(Node *root)
{
    int freq = 0;
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        freq++;

    freq += count(root->left);
    freq += count(root->right);

    return freq;
}

// inorder se check kiya
void traverse(Node *root, int &freq)
{
    if (root == NULL)
        return;

    traverse(root->left, freq);

    if (root->left == NULL && root->right == NULL)
        freq++;

    traverse(root->right, freq);
}

void noOfLeafNode(Node *root)
{
    // int freq = count(root);

    int freq = 0;
    traverse(root, freq);

    cout << " Count of leaf node is " << freq << endl;
}

int main()
{
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    Node *root = NULL;
    buildtreefromLevelorder(root);
    levelorder(root);
    noOfLeafNode(root);

    return 0;
}