#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void alltraverse(node *curr, vector<int> &pre, vector<int> &post, vector<int> &in)
{
    stack<pair<node *, int>> s;
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
}

struct node *newNode(int data)
{
    struct node *tnode = (struct node *)malloc(sizeof(struct node));
    tnode->data = data;
    tnode->left = NULL;
    tnode->right = NULL;

    return (tnode);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> pre, post, in;
    alltraverse(root, pre, post, in);

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
    return 0;
}