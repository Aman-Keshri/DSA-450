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

Node *NodeToParentMap(Node *root, int target, map<Node *, Node *> &mp)
{
    queue<Node *> q;
    Node *tgnode;

    q.push(root);
    mp[root] = NULL;

    while (!q.empty())
    {
        Node *frontnode = q.front();
        q.pop();

        if (frontnode->data == target)
            tgnode = frontnode;

        if (frontnode->left)
        {
            mp[frontnode->left] = frontnode;
            q.push(frontnode->left);
        }

        if (frontnode->right)
        {
            mp[frontnode->right] = frontnode;
            q.push(frontnode->right);
        }
    }

    return tgnode;
}

vector<int> solve(Node *root, int k, map<Node *, Node *> &mp)
{
    vector<int> ans;
    int count = 0;
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        while (size--)
        {
            Node *frontNode = q.front();
            q.pop();

            // left
            if (frontNode->left && !visited[frontNode->left])
            {
                flag = true;
                q.push(frontNode->left);
                visited[frontNode->left] = true;
            }

            // right
            if (frontNode->right && !visited[frontNode->right])
            {
                flag = true;
                q.push(frontNode->right);
                visited[frontNode->right] = true;
            }

            // parent
            if (mp[frontNode] && !visited[mp[frontNode]])
            {
                flag = true;
                q.push(mp[frontNode]);
                visited[mp[frontNode]] = true;
            }
        }
        if (flag == true)
        {
            count++;
        }
        if (count == k)
        {
            break;
        }
    }

    while (!q.empty())
    {
        Node *node = q.front();
        ans.push_back(node->data);
        q.pop();
    }

    return ans;
}

vector<int> nodesatKdistance(Node *root, int target, int k)
{
    vector<int> ans;
    if (k == 0)
    {
        ans.push_back(target);
        return ans;
    }

    map<Node *, Node *> mp;

    Node *targetNode = NodeToParentMap(root, target, mp);

    ans = solve(targetNode, k, mp);

    return ans;
}

int main()
{

    struct Node *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    root->right->right->right = newNode(10);

    // int ans = nodesatKdistance(root);

    // cout << "Max Height of Binary tree is - " << ans << "\n";

    vector<int> ans = nodesatKdistance(root, 5, 2);

    for (auto i : ans)
        cout << i << "  ";

    return 0;
}