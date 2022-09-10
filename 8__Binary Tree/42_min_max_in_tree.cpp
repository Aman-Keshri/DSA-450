/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

/*
    The first value of the pair must be the minimum value in the tree and
    the second value of the pair must be the maximum value in the tree
*/
#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, int &mini, int &maxi)
{
    if (root == NULL)
        return;

    if (root->data > maxi)
        maxi = root->data;

    if (root->data < mini)
        mini = root->data;

    solve(root->left, mini, maxi);
    solve(root->right, mini, maxi);
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    // Write your code here
    int mini = INT_MAX;
    int maxi = INT_MIN;

    solve(root, mini, maxi);
    pair<int, int> p = {mini, maxi};

    return p;
}