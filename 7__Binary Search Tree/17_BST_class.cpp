
class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    BinaryTreeNode<int> *minnode(BinaryTreeNode<int> *root)
    {
        while (root->left)
            root = root->left;

        return root;
    }

    BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int val)
    {
        // base case
        if (root == NULL)
            return root;

        // if value found in the node
        if (root->data == val)
        {
            // 0 child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // 1 child
            // left child
            if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                delete root;
                return temp;
            }

            // right child
            if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if (root->left != NULL && root->right != NULL)
            {
                // find the min from right subtree
                int mini = minnode(root->right)->data;

                // set the root to that min value
                root->data = mini;

                // now delete the min value from right subtree
                root->right = deleteNode(root->right, mini);

                return root;
            }
        }

        // if value is less than current node go left
        else if (root->data > val)
        {
            root->left = deleteNode(root->left, val);
            return root;
        }

        // if value is more than current node go right
        else
        {
            root->right = deleteNode(root->right, val);
            return root;
        }

        return root;
    }

    void remove(int data)
    {
        // Implement the remove() function
        root = deleteNode(root, data);
    }

    void preorder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        // N:L:x,R:y
        cout << root->data << ":";
        if (root->left)
            cout << "L:" << root->left->data << ",";
        if (root->right)
            cout << "R:" << root->right->data;
        cout << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void print()
    {
        // Implement the print() function
        preorder(root);
    }

    BinaryTreeNode<int> *inserttoBST(BinaryTreeNode<int> *&root, int d)
    {
        if (root == NULL)
        {
            root = new BinaryTreeNode<int>(d);
            return root;
        }

        if (d > root->data)
            root->right = inserttoBST(root->right, d);
        else
            root->left = inserttoBST(root->left, d);

        return root;
    }

    void insert(int data)
    {
        // Implement the insert() function
        root = inserttoBST(root, data);
    }

    bool searchBST(BinaryTreeNode<int> *root, int target)
    {
        if (root == NULL)
            return false;

        if (root->data == target)
            return true;

        if (root->data < target)
            return searchBST(root->right, target);

        else
            return searchBST(root->left, target);
    }

    bool search(int target)
    {
        // Implement the search() function
        if (root == NULL)
            return false;

        return searchBST(root, target);
    }
};