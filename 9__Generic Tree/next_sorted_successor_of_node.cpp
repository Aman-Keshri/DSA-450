// CPP program to find next larger element
// in an n-ary tree.
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
struct Node
{
    int key;
    vector<Node *> child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}

void nextLargerElementUtil(Node *root, int x, Node **res)
{
    if (root == NULL)
        return;

    // if root is less than res but greater than
    // x update res
    if (root->key > x)
        if (!(*res) || (*res)->key > root->key)
            *res = root;

    // Number of children of root
    int numChildren = root->child.size();

    // Recur calling for every child
    for (int i = 0; i < numChildren; i++)
        nextLargerElementUtil(root->child[i], x, res);

    return;
}

// Function to find next Greater element of x in tree
Node *nextLargerElement(Node *root, int x)
{
    // resultant node
    Node *res = NULL;

    // calling helper function
    nextLargerElementUtil(root, x, &res);

    return res;
}

// Driver program
int main()
{
    /* Let us create below tree
     *			 5
     *		 / | \
     *		 1 2 3
     *	 / / \ \
     *	 15 4 5 6
     */

    Node *root = newNode(5);
    (root->child).push_back(newNode(1));
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(3));
    (root->child[0]->child).push_back(newNode(15));
    (root->child[1]->child).push_back(newNode(4));
    (root->child[1]->child).push_back(newNode(5));
    (root->child[2]->child).push_back(newNode(6));

    int x = 5;

    cout << "Next larger element of " << x << " is ";
    cout << nextLargerElement(root, x)->key << endl;

    return 0;
}
