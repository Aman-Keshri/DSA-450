// Following is the Binary Tree node structure
/**************
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
***************/

// Given the binary Tree and two nodes say ‘p’ and ‘q’.
// Determine whether the two nodes are cousins of each other or not.
// Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
// Do it in O(n).

bool isSibling(BinaryTreeNode<int> *root, int data_one,
               int data_two)
{
    if (!root)
        return false;

    // Compare the two given nodes with
    // the childrens of current node
    if (root->left && root->right)
    {
        int left = root->left->data;
        int right = root->right->data;

        if (left == data_one && right == data_two)
            return true;
        else if (left == data_two && right == data_one)
            return true;
    }

    // Check for left subtree
    if (root->left)
        isSibling(root->left, data_one,
                  data_two);

    // Check for right subtree
    if (root->right)
        isSibling(root->right, data_one,
                  data_two);
}

// Recursive function to find level of Node 'ptr' in a binary tree
int level(BinaryTreeNode<int> *root, int ptr, int lev)
{
    // base cases
    if (root == NULL)
        return 0;
    if (root->data == ptr)
        return lev;

    // Return level if Node is present in left subtree
    int l = level(root->left, ptr, lev + 1);
    if (l != 0)
        return l;

    // Else search in right subtree
    return level(root->right, ptr, lev + 1);
}

// Returns 1 if a and b are cousins, otherwise 0
bool isCousin(BinaryTreeNode<int> *root, int a, int b)
{
    // 1. The two Nodes should be on the same level in the binary tree.
    // 2. The two Nodes should not be siblings (means that they should
    //  not have the same parent Node).
    if ((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b)))
        return true;
    else
        return false;
}
