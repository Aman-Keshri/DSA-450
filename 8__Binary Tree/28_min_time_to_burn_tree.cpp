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

// Step 1: create a map for node to it's parent
// Step 2: find the target node
// Step 3: burn the tree in min time

// function to create node to parent map and return the target node
// will do so using level order traversal
Node *createParentMap(Node *root, int target, map<Node *, Node *> &mp)
{
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);
    // root will have parent as NULL
    mp[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        // if the curent node is target node sotre it in result
        if (front->data == target)
            res = front;

        // map the left and right child to it's parent while traversing
        if (front->left)
        {
            mp[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            mp[front->right] = front;
            q.push(front->right);
        }
    }
    // return the traget node
    return res;
}

// function to calculate time to burn the complete tree
// for the BFS(Breadth first search) method is used
int burnTree(Node *root, map<Node *, Node *> &mp)
{
    // 2 data structure are required
    //  map to keep track of visited node and queue to keep track of new nodes to traverse
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        // for each node traverse all the neighbour nodes at once and then move to next node
        // so another loop is used that will run till the number of elements present during 1st entry
        int size = q.size();
        bool flag = 0;
        while (size--)
        {
            // extract 1st node
            Node *front = q.front();
            q.pop();

            // first check it's left node is present and not visited then add it to queue and mark visited
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }

            // second check it's right node is present and not visited then add it to queue and mark visited
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            // third check it's parent node is present and not visited then add it to queue and mark visited
            // parent node can be found from the map
            if (mp[front] && !visited[mp[front]])
            {
                flag = 1;
                q.push(mp[front]);
                visited[mp[front]] = true;
            }
        }
        // each time we add to queue change the flag to 1 so as to keep track that new element is added
        // thus we can increase the time as neighbour nodes are burnt
        if (flag == 1)
            ans++;
    }
    return ans;
}

// driver function
int minTime(Node *root, int target)
{
    int ans;
    map<Node *, Node *> nodeToparent;
    Node *targetNode = createParentMap(root, target, nodeToparent);

    // start burn from target node
    ans = burnTree(targetNode, nodeToparent);

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
    root->left->right->left = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    int ans = minTime(root, 6);

    cout << "Time to burn Binary tree is - " << ans << "\n";

    // vector<int> ans = function(root);

    // for (auto i : ans)
    //     cout << i << "  ";

    return 0;
}