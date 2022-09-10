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

/* Find the inorder predecessor of current */
// move one left and then keep moving right until right is NULL
Node *predecessor(Node *node)
{
    Node *cur = node;

    cur = cur->left;

    while (cur->right != NULL && cur->right != node)
    {
        cur = cur->right;
    }
    return cur;
}

vector<int> morrisInorder(Node *root)
{
    Node *curr = root;
    vector<int> ans;

    if (root == NULL)
        return ans;

    while (curr != NULL)
    {
        //     If the current does not have left child
        //   a) Print current’s data
        //   b) Go to the right, i.e., current = current->right
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // Find rightmost node in current left subtree OR
            //   node whose right child == current.
            Node *prd = predecessor(curr);

            // IF
            //  a) Make current as the right child of that rightmost
            //     node we found; and
            //  b) Go to this left child, i.e., current = current->left
            if (prd->right == NULL)
            {
                prd->right = curr;
                curr = curr->left;
            }

            // Else we found right child == current
            //  a) Update the right child as NULL of that node whose right child is current
            //  b) Print current’s data
            //  c) Go to the right, i.e. current = current->right
            else
            {
                prd->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
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
    // root->right->left = newNode(6);
    root->right->right = newNode(6);
    root->left->left->right = newNode(7);
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    vector<int> ans = morrisInorder(root);

    for (auto i : ans)
        cout << i << "  ";

    return 0;
}