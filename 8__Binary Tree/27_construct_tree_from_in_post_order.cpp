// C++ program to construct a tree using
// inorder and preorder traversal
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// create map of element to index
void createMap(int in[], map<int, int> &mp, int n)
{
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
}

// int findPosition(int in[], int element, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (in[i] == element)
//             return i;
//     }
//     return -1;
// }

// Function to build tree using given traversal
Node *solve(int in[], int post[], int &index, int instart, int inend, int n, map<int, int> &mp)
{
    // base case
    if (index < 0 || instart > inend)
        return NULL;

    // take a element from preorder
    int element = post[index--];
    // create a new node for that element
    Node *root = new Node(element);
    // find the position of the element in inorder list
    // int position = findPosition(in, element, n);
    int position = mp[element];

    // recursive calls
    // for post order first right subtree is built
    root->right = solve(in, post, index, position + 1, inend, n, mp);
    root->left = solve(in, post, index, instart, position - 1, n, mp);

    return root;
}

Node *buildTree(int postorder[], int inorder[], int n)
{
    int postIndex = n - 1;
    map<int, int> mp;
    // inorder mapping
    createMap(inorder, mp, n);
    Node *ans = solve(inorder, postorder, postIndex, 0, n - 1, n, mp);

    return ans;
}

// Function to print tree in Inorder
void printInorder(Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->val << " ";

    /* now recur on right child */
    printInorder(node->right);
}

// Driver code
int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);

    // Function Call
    Node *root = buildTree(in, post, n);

    cout << "Preorder of the constructed tree : \n";

    printInorder(root);
    return 0;
}
