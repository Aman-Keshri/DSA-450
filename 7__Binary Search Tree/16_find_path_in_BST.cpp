vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    // Write your code here
    vector<int> *ans = new vector<int>;
    if (root == NULL)
        return ans;

    if (root->data == data)
    {
        ans->push_back(root->data);
        return ans;
    }

    vector<int> *result = NULL;
    if (root->data > data)
        result = getPath(root->left, data);
    else
        result = getPath(root->right, data);

    if (result->size() != 0)
        result->push_back(root->data);

    return result;
}
