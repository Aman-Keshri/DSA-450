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
    int data;
    cin >> data;

    while (data != -1)
    {
        inserttoBST(root, data);
        cin >> data;
    }
}

void levelorder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    cout << "level order\n";
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

void alltraverse(Node *curr)
{
    vector<int> pre;
    vector<int> post;
    vector<int> in;

    stack<pair<Node *, int>> s;
    s.push({curr, 1});

    if (curr == NULL)
        return;

    while (!s.empty())
    {
        auto ele = s.top();
        s.pop();

        if (ele.second == 1)
        {
            pre.push_back(ele.first->data);
            ele.second++;
            s.push(ele);

            if (ele.first->left != NULL)
            {
                s.push({ele.first->left, 1});
            }
        }

        else if (ele.second == 2)
        {
            in.push_back(ele.first->data);
            ele.second++;
            s.push(ele);

            if (ele.first->right != NULL)
            {
                s.push({ele.first->right, 1});
            }
        }
        else
            post.push_back(ele.first->data);
    }

    cout << "1. Preorder - \n";
    for (auto val : pre)
    {
        cout << val << " ";
    }
    cout << "\n2. Postorder - \n";
    for (auto val : post)
    {
        cout << val << " ";
    }
    cout << "\n3. Inorder - \n";
    for (auto val : in)
    {
        cout << val << " ";
    }
}

int main()
{
    Node *root = NULL;
    // 50 30 20 40 70 60 80 -1
    cout << "Enter data to create BST tree\n";
    takeInput(root);

    levelorder(root);
    alltraverse(root);

    return 0;
}