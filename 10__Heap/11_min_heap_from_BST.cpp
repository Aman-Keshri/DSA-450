// C++ implementation to convert the given
// BST to Min Heap

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node
{

    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node *getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node *);

// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node *root, vector<int> &arr)
{
    // base case
    if (root == NULL)
        return;

    // first recur on left subtree
    inorderTraversal(root->left, arr);

    // then copy the data of the node
    arr.push_back(root->data);

    // now recur for right subtree
    inorderTraversal(root->right, arr);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node *root, vector<int> arr, int &i)
{
    // base case
    if (root == NULL)
        return;
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[i++];

    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);

    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node *root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> inorderList;
    int i = 0;

    // inorder traversal to populate 'arr'
    inorderTraversal(root, inorderList);

    // BST to MIN HEAP conversion
    BSTToMinHeap(root, inorderList, i);
}

// function for the preorder traversal of the tree
void preorderTraversal(Node *root)
{
    if (!root)
        return;

    // first print the root's data
    cout << root->data << " ";

    // then recur on left subtree
    preorderTraversal(root->left);

    // now recur on right subtree
    preorderTraversal(root->right);
}

/*
    Since the tree is already a complete Binary tree so no change in structure

    step 1 we know Inorder of BSt is sorted, so store inorder
    step 2 now based of the two condition provided
        I. Min Order - where Node < Left and Node < right
        II. All Left child < All right child
        Now, this two condition sum upto
        Node < Left < Right (i.e. first store Node then left and then right)
        It is same as PreOrder traversal

    step 3 traverse the given tree is Preorder way and keep assigning
    the inorder elements to each Node.

    TIME - O(N)  Space - O(N)
*/

// Driver program to test above
int main()
{
    // BST formation
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    // Function call
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);

    return 0;
}
