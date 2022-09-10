#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> result;

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

void solve(Node *root, int target, vector<int> ans)
{
    // if root null i.e notfound target yet but reached leaf node
    if (root == NULL)
        return;

    // push the data to vector
    ans.push_back(root->data);

    // if leaf node is reached and the tagret left to acheive is equal to leaf node data
    // then root to leaf sum found sotre the path
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == target)
            result.push_back(ans);
    }

    // if notfound then recurse left and right by subtracting the current node from target
    solve(root->left, target - root->data, ans);
    solve(root->right, target - root->data, ans);

    // at end if sum not found on a node remove it from the list
    ans.pop_back();
}

void roottonode(Node *root, int target)
{
    vector<int> ans;
    if (root == NULL)
        return;

    solve(root, target, ans);
}

int main()
{

    struct Node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);

    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(1);

    // int ans = function(root);

    // cout << "Max Height of Binary tree is - " << ans << "\n";

    roottonode(root, 22);

    if (result.size() == 0)
        cout << ("NA");
    else
    {
        for (auto l : result)
        {
            cout << "[";
            for (auto it : l)
            {
                cout << it << " ";
            }
            cout << "]";
            cout << endl;
        }
    }

    return 0;
}