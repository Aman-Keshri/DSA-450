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

vector<int> verticalOrder(Node *root)
{
    // declare variable
    map<int, map<int, vector<int>>> nodeMap;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    // push root
    q.push(make_pair(root, make_pair(0, 0)));

    // loop until queue is empty
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        // now we got the node now push the data of that node according
        // to it's horizontal distance and level
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodeMap[hd][level].push_back(frontNode->data);

        // push left and right to add nodes
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
    }

    // transfer the vector created in map to a ans vector
    //  or we can saqy extract the data back from map
    //  map<int,map<int,vector<int>>> nodeMap

    for (auto i : nodeMap)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    // same level pe sorted order me display ke liye
    // and vector of vector return krne ke liye
    //  for(auto i : mp)
    //      {
    //          vector<int> temp;
    //          for(auto j : i.second)
    //          {
    //              vector<int> xyz = j.second;

    //             sort(xyz.begin(), xyz.end());
    //             for(auto k : xyz)
    //                 temp.push_back(k);
    //         }
    //         ans.push_back(temp);
    //     }

    return ans;
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    vector<int> ans = verticalOrder(root);

    for (auto i : ans)
    {
        cout << i << "  ";
    }

    return 0;
}