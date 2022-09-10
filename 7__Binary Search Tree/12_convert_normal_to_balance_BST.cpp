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
    vector<int> ans = {50, 30, 20, 40, 10, 15, 80, -1};

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

void inorder(Node *root, vector<int> &inord)
{
    if (root == NULL)
        return;

    inorder(root->left, inord);
    inord.push_back(root->data);
    inorder(root->right, inord);
}

/*
balance BST means that
for every node the diffrence of height of two subtree is not more than 1

abs[height(left) - height(right)] <= 1
*/

/*
To Solve

step 1 convert the given tree to inorder and we know inorder is sorted
so the mid will the root of the new node
step 2 create a new node and assign the mid to it
step 3 the left of the root will be from start to mid - 1
        and the right will be mid+1 to  end
step 4 the right and left part will be solved by recurssion
*/

Node *inordertoBST(int start, int end, vector<int> inorderV)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *root = new Node(inorderV[mid]);

    root->left = inordertoBST(start, mid - 1, inorderV);
    root->right = inordertoBST(mid + 1, end, inorderV);

    return root;
}

Node *balanceBST(Node *root)
{
    if (root == NULL)
        return NULL;

    vector<int> inorderV;

    inorder(root, inorderV);

    return inordertoBST(0, inorderV.size() - 1, inorderV);
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    Node *ans = balanceBST(root);
    levelorder(ans);

    return 0;
}