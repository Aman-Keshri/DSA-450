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

// A simple recursive function to convert a given Binary
// tree to Doubly Linked List root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked
// list
void BinaryTree2DoubleLinkedList(Node *root, Node *&head)
{
    // Base case
    if (root == NULL)
        return;

    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all
    // recursive calls
    static Node *prev = NULL;

    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head);

    // Now convert this node
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head);
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
    // root->left->right->left = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    // int ans = function(root);

    // cout << "Max Height of Binary tree is - " << ans << "\n";
    Node *head = NULL;

    BinaryTree2DoubleLinkedList(root, head);

    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }

    return 0;
}