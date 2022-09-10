#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

struct node * newNode(int data)
{
    struct node * temp = (struct node *) malloc (sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
/*
We first need to define what is the maximum path sum through a given 
node (when that node is acting as the root node/curving point).
At a given node with a value, if we find the max leftSumPath in
the left-subtree and the max rightSumPath in the right subtree,
then the maxPathSum through that node is value+(leftSumPath+rightSumPath).

For our recursion to work, it is very important to understand what value 
we return from our function. In our recursive function, we find and compare 
the maxPathSum from a given node when it is the root/turning point of the path. 
But what we return is the maxPathSum of that same node when it is NOT 
the root/turning point of the path. To find the latter maxPath, 
we no longer have the liberty to consider both leftMaxPath and rightMaxPath, 
we will simply take the maximum of the two and it to the value of the node.

To summarize:
Initialize a maxi variable to store our final answer.
Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).
*/
int max_pathsum(node* curr, int maxi)
{
    if(curr == NULL)    
        return 0;
    int lh = max(0,max_pathsum(curr->left, maxi));
    int rh = max(0,max_pathsum(curr->right, maxi));
    int val = curr->data;

    maxi = max(maxi, (lh+rh+val));

    return max(lh,rh) + val;
}

int main()
{
    int maxi = 0;
    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);

    int maxim = max_pathsum(root, maxi);

    cout<<maxim;

    return 0;
}