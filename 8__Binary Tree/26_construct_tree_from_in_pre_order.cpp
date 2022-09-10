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
Node *solve(int in[], int pre[], int &index, int instart, int inend, int n, map<int, int> &mp)
{
    // base case
    if (index >= n || instart > inend)
        return NULL;

    // take a element from preorder
    int element = pre[index++];
    // create a new node for that element
    Node *root = new Node(element);
    // find the position of the element in inorder list
    // int position = findPosition(in, element, n);
    int position = mp[element];

    // recursive calls
    // for pre order first left subtree is built
    root->left = solve(in, pre, index, instart, position - 1, n, mp);
    root->right = solve(in, pre, index, position + 1, inend, n, mp);

    return root;
}

Node *buildTree(int preorder[], int inorder[], int n)
{
    int preIndex = 0;
    map<int, int> mp;
    // inorder mapping
    createMap(inorder, mp, n);
    Node *ans = solve(inorder, preorder, preIndex, 0, n - 1, n, mp);

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
    int in[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
    int pre[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};
    int len = sizeof(in) / sizeof(int);

    Node *root = buildTree(pre, in, len);

    printInorder(root);
    return 0;
}
