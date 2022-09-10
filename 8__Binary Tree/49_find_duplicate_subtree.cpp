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
map<string, int> mp;

string solve(Node *root)
{
    if (root == NULL)
        return "#";

    string s = "";

    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }

    s += to_string(root->data);
    s += solve(root->left);
    s += solve(root->right);

    mp[s]++;

    return s;
}

int dupsubtree(Node *root)
{
    solve(root);
    for (auto i : mp)
    {
        if (i.second >= 2)
            return true;
    }
    return false;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(4);
    root->right->right = newNode(6);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    bool ans = dupsubtree(root);

    cout << "Duplicate in Binary tree is (present - 1 / not present - 0)  " << ans << "\n";

    return 0;
}