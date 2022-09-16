// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    // function to count the number of nodes in binary tree
    // Time - O(N)
    int countNode(struct Node *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNode(root->left) + countNode(root->right);

        return ans;
    }

    // A Binary Tree to be complete the count of index and count of nodes should
    // match as complete binary tree is always filled from left
    // so no space should be present in nodes
    // as the index should always be less than count (in 0 based index)
    // and the index should always be less than equal to count (in 0 based index)

    /*
        step 1 base case if null true
        step 2 check if index in less than counter if not false
        step 3 if index is less then,
                recur left and right to check
        step 4 if both left and right are true return true else false
    */
    // Time - O(N)
    bool isCBT(struct Node *root, int index, int count)
    {
        if (root == NULL)
            return true;

        if (index >= count)
            return false;

        else
        {
            bool left = isCBT(root->right, 2 * index + 1, count);
            bool right = isCBT(root->right, 2 * index + 2, count);

            return (left && right);
        }
    }

    /*
    function will reach here if the binary tree is CBT so only check for CBT condn
        it also has three cases
        step 1 if leaf node then return true as leaf nodes are in heap
        step 2 if right node is NULL then check that root > left return
        step 3 if nodes has two child
                check for left and right child
                then check that right and left are < root
                if all are true then true else false
    */
    // Time - O(N)
    bool isMaxOrder(struct Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return (left && right &&
                    (root->data > root->right->data && root->data > root->left->data));
        }
    }

    // main function
    // steps
    /*
        step 1 count the total number of nodes in tree
        step 2 A binary tree to be in Heap it needs to satisfy 2 property
            I. It must be complete binary tree
            II. It must satisfy the Heap property of Max heap or Min Heap
        step 3 check if the tree satisfy the two condition and then return T/F.
    */
    // Time - O(N) space - O(N)
    bool isHeap(struct Node *root)
    {
        // code here
        int index = 0;
        int totalCount = countNode(root);
        if (isCBT(root, index, totalCount) && isMaxOrder(root))
            return true;
        else
            return false;
    }
};