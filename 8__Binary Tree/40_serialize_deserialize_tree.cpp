#include <bits/stdc++.h>
#include <string>

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

string serialize(Node *root)
{
    queue<Node *> q;
    string ans = "";
    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
            ans.append("@");
        else
            ans.append(to_string(frontNode->data));

        if (frontNode)
        {
            q.push(frontNode->left);
            q.push(frontNode->right);
        }
    }

    return ans;
}

Node *deserialize(string tree)
{
    int size = tree.size();

    if (size == 0)
        return NULL;

    queue<Node *> q;
    Node *root = newNode(tree[0] - '0');
    int index = 1;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (tree[index] == '@')
            frontNode->left = NULL;
        else
        {
            int no = tree[index] - '0';
            Node *lNode = newNode(no);
            frontNode->left = lNode;
            q.push(frontNode->left);
        }
        index++;

        if (tree[index] == '@')
            frontNode->right = NULL;
        else
        {
            int no = tree[index] - '0';
            Node *rNode = newNode(no);
            frontNode->right = rNode;
            q.push(frontNode->right);
        }
        index++;
    }
    return root;
}

string serialize1(Node *root)
{
    queue<Node *> q;
    string ans = "";
    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
            ans.append("@,");
        else
            ans.append(to_string(frontNode->data) + ',');

        if (frontNode)
        {
            q.push(frontNode->left);
            q.push(frontNode->right);
        }
    }

    return ans;
}

Node *deserialize1(string data)
{
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');
    Node *root = newNode(stoi(str));

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "@")
            frontNode->left = NULL;
        else
        {
            Node *lNode = newNode(stoi(str));
            frontNode->left = lNode;
            q.push(lNode);
        }

        getline(s, str, ',');
        if (str == "@")
            frontNode->right = NULL;
        else
        {
            Node *rNode = newNode(stoi(str));
            frontNode->right = rNode;
            q.push(rNode);
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    // struct Node *root = newNode(4);
    // root->left = newNode(-7);
    // root->right = newNode(-3);

    // root->right->left = newNode(-9);
    // root->right->right = newNode(-3);

    // root->right->left->left = newNode(9);
    // root->right->left->right = newNode(-7);
    // root->right->right->left = newNode(-4);

    // root->right->left->left->left = newNode(6);
    // root->right->left->right->left = newNode(-6);
    // root->right->right->right->right = newNode(6);

    // root->right->left->left->left->left = newNode(0);
    // root->right->left->left->left->right = newNode(6);
    // root->right->left->right->left->left = newNode(5);
    // root->right->right->right->right->right = newNode(9);

    // root->right->left->left->left->left->right = newNode(-1);
    // root->right->left->left->left->right->left = newNode(-4);
    // root->right->right->right->right->right->right = newNode(-2);

    cout << "original tree \n";
    inorder(root);

    string ans = serialize1(root);
    cout << "\nBinary tree is  " << ans << "\n";

    Node *ansRoot = deserialize1(ans);
    cout << "deserialized tree is \n";
    inorder(ansRoot);

    return 0;
}