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

/*
this approach will work on the range of each node technique
just check if the current index element is in range or not
if yes add it if no return back with NULL

solve for 1 step rest recursion will do

Time - O(3N) - each node is visited 3 times
Space = O(N)
*/
Node *solve(vector<int> &preorder, int mini, int maxi, int &index)
{
    // if current index is greater than preorder list return NULL
    if (index >= preorder.size())
        return NULL;

    // if the element does not lie in the curent given range of the node then return NULL
    if (preorder[index] < mini || preorder[index] > maxi)
        return NULL;

    // if not satisfied above cndition then that means it must have a element that lie in range
    Node *root = new Node(preorder[index++]);

    root->left = solve(preorder, mini, root->data, index);
    root->right = solve(preorder, root->data, maxi, index);

    return root;
}

// we can solve it using only upper bound
/*
    if index has passed list size
    or the element at curent index is greater than bound
    return NULL

    assign the element as root and
    its left will called with bound as root->data(curr node data)
    as then it's right will be called using the previous bound

*/
Node *solve1(vector<int> preorder, int &index, int bound)
{
    if (index == preorder.size() || preorder[index] > bound)
        return NULL;

    Node *root = new Node(preorder[index++]);
    root->left = solve1(preorder, index, root->data);
    root->right = solve1(preorder, index, bound);

    return root;
}

Node *preordertoBST(vector<int> preorder)
{
    int mini = INT_MIN, maxi = INT_MAX;

    int index = 0;
    // return solve(preorder, mini, maxi, index);
    return solve1(preorder, index, maxi);
}

int main()
{
    //{50, 30, 20, 40, 70, 60, 80, -1}
    // Node *root = NULL;

    // cout << "Enter data to create BST tree\n";
    // takeInput(root);
    // levelorder(root);

    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    Node *ans = preordertoBST(preorder);
    levelorder(ans);

    return 0;
}