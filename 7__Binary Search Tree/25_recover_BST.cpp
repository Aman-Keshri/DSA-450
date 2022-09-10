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

Node *first, *middle, *last, *prev;

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    if (prev != NULL && (root->data < prev->data))
    {
        // if first violation found update first and middle
        if (first == NULL)
        {
            first = prev;
            middle = root;
        }
        // if prev already has a element(i.e. found the second )
        // update the last
        else
            last = root;
    }

    // before moving to next element update prev;
    prev = root;
    inorder(root->right);
}

void recoverTree(Node *root)
{
    first = middle = last = NULL;
    prev = new Node(INT_MIN);

    inorder(root);

    // if first and last is present (i.e. two violation found)
    if (first && last)
        swap(first->data, last->data);

    // else only one violation found
    else if (first && middle)
        swap(first->data, middle->data);
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;
    vector<int> order = {50, 30, 20, 40, 70, 60, 80, -1};
    cout << "Enter data to create BST tree\n";
    takeInput(root, order);
    levelorder(root);

    return 0;
}