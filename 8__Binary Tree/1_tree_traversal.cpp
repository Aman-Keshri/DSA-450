/*
this program contains Interative approach to diffrent binary tree traversal techniques
1. Inorder
2. preorder
3. Postorder
4. Levelorder
5. Levelorder with new line for each level
6. reverse levelorder
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

// Inorder traversal
vector<int> Inordertrav(node *curr)
{
    vector<int> inorder;
    stack<node *> s;

    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top();
            inorder.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }
    }
    return inorder;
}

// preorder traversal
vector<int> Preordertrav(node *curr)
{
    vector<int> preorder;
    if (curr == NULL)
        return preorder;

    stack<node *> s;
    s.push(curr);

    while (!s.empty())
    {
        node *tnode = s.top();
        preorder.push_back(tnode->data);
        s.pop();

        if (tnode->right != NULL)
            s.push(tnode->right);
        if (tnode->left != NULL)
            s.push(tnode->left);
    }
    return preorder;
}

// postorder traversal with 2 stacks
vector<int> Postordertrav(node *curr)
{
    vector<int> postorder;
    if (curr == NULL)
        return postorder;

    stack<node *> s1, s2;

    s1.push(curr);

    while (!s1.empty())
    {
        node *tnode = s1.top();
        s1.pop();
        s2.push(tnode);
        if (tnode->left != NULL)
            s1.push(tnode->left);
        if (tnode->right != NULL)
            s1.push(tnode->right);
    }

    while (!s2.empty())
    {
        node *tnode = s2.top();
        postorder.push_back(tnode->data);
        s2.pop();
    }

    return postorder;
}

// postorder traversal with 1 stacks
vector<int> Post1ordertrav(node *curr)
{
    vector<int> postorder;
    stack<node *> s;
    if (curr == NULL)
        return postorder;

    while (curr != NULL || !s.empty())
    {

        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                postorder.push_back(temp->data);

                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    return postorder;
}

// Levelorder traversal
vector<int> levelordertrav(node *curr)
{
    vector<int> levelorder;
    queue<node *> q;

    q.push(curr);

    while (!q.empty())
    {
        node *tnode = q.front();
        q.pop();
        if (tnode->left != NULL)
            q.push(tnode->left);
        if (tnode->right != NULL)
            q.push(tnode->right);

        levelorder.push_back(tnode->data);
    }

    return levelorder;
}

// Levelorder traversal with endl after each level
void levelorder(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Reverse Levelorder traversal
void reverselevelorder(node *root)
{
    queue<node *> q;
    stack<node *> s;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    while (!s.empty())
    {
        node *stemp = s.top();
        s.pop();
        cout << stemp->data << " ";
    }
}

struct node *newNode(int data)
{
    struct node *tnode = (struct node *)malloc(sizeof(struct node));
    tnode->data = data;
    tnode->left = NULL;
    tnode->right = NULL;

    return (tnode);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> inOrder;
    inOrder = Inordertrav(root);

    cout << "1. The inOrder Traversal is : ";
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout << inOrder[i] << " ";
    }

    vector<int> preOrder;
    preOrder = Preordertrav(root);

    cout << "\n2. The PreOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }

    vector<int> postOrder;
    postOrder = Postordertrav(root);

    cout << "\n3. The PostOrder 2 stacks Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }

    vector<int> levelOrder;
    levelOrder = levelordertrav(root);

    cout << "\n4. The levelOrder Traversal is : ";
    for (int i = 0; i < levelOrder.size(); i++)
    {
        cout << levelOrder[i] << " ";
    }

    vector<int> post1Order;
    post1Order = Post1ordertrav(root);

    cout << "\n5. The PostOrder 1 stack Traversal is : ";
    for (int i = 0; i < post1Order.size(); i++)
    {
        cout << post1Order[i] << " ";
    }

    cout << "\n6. The levelOrder Traversal with each level in new line is : \n";
    levelorder(root);

    cout << "\n7. Reverse Level Order Traversal: \n";
    reverselevelorder(root);

    return 0;
}