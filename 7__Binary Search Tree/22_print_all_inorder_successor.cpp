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

// using vector
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void populateNext(Node *root)
{
    // code here
    vector<int> ans;
    inorder(root, ans);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << "->-1 ";
        else
            cout << ans[i] << "->" << ans[i + 1] << " ";
    }
}

// creating new nodes to connect
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/

void solve1(Node *root, Node *&p)
{
    if (root == NULL)
        return;

    // go left
    solve1(root->left, p);

    // if p node is still null then assign root to p
    // else p is not null then assign p->next to root
    if (p != NULL)
        p->next = root;
    p = root;

    // go right
    solve1(root->right, p);
}

void populateNext1(Node *root)
{
    // code here
    Node *p = NULL;
    solve1(root, p);
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;
    vector<int> order = {50, 30, 20, 40, 70, 60, 80, -1};
    cout << "Enter data to create BST tree\n";
    takeInput(root, order);
    levelorder(root);

    populateNext1(root);

    return 0;
}
