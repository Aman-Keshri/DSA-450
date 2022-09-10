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

vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            while (temp)
            {
                ans.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
    }
    return ans;
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

    vector<int> ans = diagonalTraversal(root);

    for (auto i : ans)
        cout << i << "  ";

    return 0;
}