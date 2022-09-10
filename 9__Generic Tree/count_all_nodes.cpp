/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int sumOfNodes(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;

    int count = 0;
    int s = root->children.size();
    for (int i = 0; i < s; i++)
    {
        count += sumOfNodes(root->children[i]);
    }
    count++;
    return count;
}