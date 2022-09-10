#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

bool check(Node *root)
{
    queue<Node *> q;
    map<int, vector<int>> mp;

    int level = 0;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans;
        while (size--)
        {
            Node *front = q.front();
            q.pop();

            if (front->left == NULL && front->right == NULL)
                ans.push_back(front->data);

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
        mp[level] = ans;
        level++;
    }

    int count = 0;
    for (auto i : mp)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
        if (i.second.size() > 0)
            count++;
    }

    if (count == 1)
        return true;
    else
        return false;
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    bool ans = check(root);

    cout << "all leaf nodes at same level of Binary tree (0-false/1 - true)- " << ans << "\n";

    return 0;
}