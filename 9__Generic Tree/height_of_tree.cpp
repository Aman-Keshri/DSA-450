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
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

#include "solution.h"

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int getHeight(TreeNode<int> *root)
{
    // Write your code here

    if (root == NULL)
        return 0;

    // leaf node
    if (root->children.size() == 0)
    {
        return 1;
    }

    int max_child_height = INT_MIN;

    // height=1+max(subtree heights)
    // subtree heights found recursively
    for (int i = 0; i < root->children.size(); i++)
    {
        max_child_height = max(max_child_height, getHeight(root->children[i]));
    }
    return 1 + max_child_height;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << getHeight(root);
}
