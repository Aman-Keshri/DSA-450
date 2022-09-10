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

void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

// time = O(N)  space - O(N)
pair<int, int> twoSum(Node *root, int target)
{
    vector<int> in;
    pair<int, int> ans;
    ans = {-1, -1};
    inOrder(root, in);

    int i = 0, j = in.size() - 1;

    while (i < j)
    {
        int curSum = in[i] + in[j];
        if (curSum == target)
        {
            ans = {in[i], in[j]};
            return ans;
        }

        if (curSum < target)
            i++;

        if (curSum > target)
            j--;
    }

    return ans;
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    Node *root = NULL;

    cout << "Enter data to create BST tree\n";
    takeInput(root);
    levelorder(root);

    pair<int, int> ans = twoSum(root, 130);
    cout << "pair with sum is  " << ans.first << "  " << ans.second << endl;
    return 0;
}