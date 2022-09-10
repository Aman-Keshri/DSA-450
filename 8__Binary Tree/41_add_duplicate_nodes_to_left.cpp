/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.

************************************************************/

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

void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(root->data);
    node->left = root->left;
    root->left = node;

    insertDuplicateNode(node->left);
    insertDuplicateNode(root->right);
}