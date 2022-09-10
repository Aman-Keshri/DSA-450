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

// in BST inorder gives sorted list so do inorder and find the kth node
//  in case of kth largest find n-k+1 th smallest element
void kthsmallest(Node *root, int &i, int k, int &ans)
{
    if (root == NULL)
        return;

    kthsmallest(root->left, i, k, ans);
    i++;
    if (i == k)
        ans = root->data;
    kthsmallest(root->right, i, k, ans);
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    int i = 0, ans = 0, k = 2;
    kthsmallest(root, i, k, ans);
    cout << "kth smallest is BST is  " << ans << endl;

    i = 0, ans = 0, k = 2;
    kthsmallest(root, i, (7 - k + 1), ans);
    cout << "kth largest is BST is  " << ans << endl;
    return 0;
}