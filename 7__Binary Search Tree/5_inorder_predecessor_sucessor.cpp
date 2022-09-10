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

void presuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    if (root->data == key)
    {
        // predecessor is max from left
        if (root->left)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;

            pre = temp;
        }

        // sucessor is min from right
        if (root->right)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;

            suc = temp;
        }
        return;
    }

    // if key is smaller  go to left subtree
    if (root->data > key)
    {
        suc = root;
        presuc(root->left, pre, suc, key);
    }

    // go to right subtree
    else
    {
        pre = root;
        presuc(root->right, pre, suc, key);
    }
}

pair<int, int> predsucc(Node *root, int key)
{
    Node *temp = root;
    int pred = -1, succ = -1;

    // loop to find the key and in way keep record of possible pred and succ
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }

        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // find pred and succ

    // pred will be the max from left subtree i.e. right most of left subtree
    Node *leftTree = temp->left;
    while (leftTree)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ will be the min from right subtree i.e. left most of the right subtree
    Node *rightTree = temp->right;
    while (rightTree)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = {pred, succ};
    return ans;
}

// Time - O(N) space - O(1)
int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;
    Node *pre = NULL, *suc = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);
    presuc(root, pre, suc, 65);

    if (pre != NULL)
        cout << "Predecessor is " << pre->data << endl;
    else
        cout << "No Predecessor\n";

    if (suc != NULL)
        cout << "Successor is " << suc->data;
    else
        cout << "No Successor\n";

    cout << "\n\nIterative way to check\n";
    pair<int, int> ans = predsucc(root, 70);

    cout << "\nPred  " << ans.first << "  succ  " << ans.second << endl;

    return 0;
}