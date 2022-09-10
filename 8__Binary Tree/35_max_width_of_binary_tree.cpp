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

int maxwidth(Node *root)
{
    // level order traversal is used
    queue<pair<Node *, int>> q;
    int ans = 0;

    if (root == NULL)
        return 0;

    q.push({root, 0});

    // need to traverese and keep track of 1st and last node index of each level
    while (!q.empty())
    {
        int size = q.size();
        // store the minimum index
        int mini = q.front().second;
        int first, last;

        // loop through all nodes of each level
        for (int i = 0; i < size; i++)
        {
            // store front node
            Node *frontnode = q.front().first;
            int curIndex = q.front().second - mini;
            q.pop();

            // first will be leftmost index
            if (i == 0)
                first = curIndex;
            // last will be last most index
            if (i == size - 1)
                last = curIndex;

            // if node has left or right push in queue
            if (frontnode->left)
                q.push({frontnode->left, (curIndex * 2 + 1)});
            if (frontnode->right)
                q.push({frontnode->right, (curIndex * 2 + 2)});
        }
        // ans will be max btwn current ans and last - first + 1
        ans = max(ans, last - first + 1);
    }
    return ans;
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

    int ans = maxwidth(root);

    cout << "Max width of Binary tree is - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}