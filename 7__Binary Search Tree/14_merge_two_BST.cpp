#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inserttoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = inserttoBST(root->right, d);
    else
        root->left = inserttoBST(root->left, d);

    return root;
}

void takeInput(Node *&root, vector<int> ans)
{
    for (auto data : ans)
    {
        if (data != -1)
            inserttoBST(root, data);
    }
}

void levelorder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    cout << "Level Order\n";
    while (!q.empty())
    {
        Node *temp = q.front();
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

/*
approach 1
    step 1 convert BST into inorder
    step 2 merge both inorder list
    step 3 create a tree from inorder
*/

void inorder(Node *root, vector<int> &inord)
{
    if (root == NULL)
        return;

    inorder(root->left, inord);
    inord.push_back(root->data);
    inorder(root->right, inord);
}

vector<int> mergeInorder(vector<int> inoder1, vector<int> inoder2)
{
    vector<int> ans;
    int i = 0, j = 0;
    int n1 = inoder1.size(), n2 = inoder2.size();
    while (i < n1 && j < n2)
    {
        if (inoder1[i] < inoder2[j])
        {
            ans.push_back(inoder1[i]);
            i++;
        }
        else
        {
            ans.push_back(inoder2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        ans.push_back(inoder1[i]);
        i++;
    }
    while (j < n2)
    {
        ans.push_back(inoder2[j]);
        j++;
    }
    return ans;
}

Node *inordertoBST(int start, int end, vector<int> inorderV)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *root = new Node(inorderV[mid]);

    root->left = inordertoBST(start, mid - 1, inorderV);
    root->right = inordertoBST(mid + 1, end, inorderV);

    return root;
}

Node *mergeBST1(Node *root1, Node *root2)
{
    // step 1
    vector<int> inoder1;
    vector<int> inoder2;
    inorder(root1, inoder1);
    inorder(root2, inoder2);

    // step 2
    vector<int> inoder = mergeInorder(inoder1, inoder2);

    // step 3
    Node *root = inordertoBST(0, inoder.size() - 1, inoder);
    return root;
}

/*
Approach 2
    here instead of using vector to store the inorder do implace pointer change to
    flatten the BST (left to NULL and right to next Node)

    step 1 convert BST into inorder Linked List
    step 2 merge both inorder Linked List
    step 3 create a tree from inorder Linked List
*/

/*
    In this function
    using recursion what weare acheiving is
    step 1  first flatten the rigt side of the tree
    step 2  attach the head pointer of right side to root node
    step 3  flatten the left side

*/
void convertIntoDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    convertIntoDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;

    convertIntoDLL(root->left, head);
}

Node *mergeDLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->right;
    }
    return count;
}

Node *sortedDLLtoBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = sortedDLLtoBST(head, n / 2);

    Node *root = head;
    root->left = left;
    head = head->right;

    root->right = sortedDLLtoBST(head, n - (n / 2) - 1);

    return root;
}

Node *mergeBST2(Node *root1, Node *root2)
{
    // step 1
    Node *head1 = NULL;
    Node *head2 = NULL;
    convertIntoDLL(root1, head1);
    convertIntoDLL(root2, head2);
    head1->left = NULL;
    head2->left = NULL;

    // step 2
    Node *head = mergeDLL(head1, head2);

    // step 3
    int n = countNodes(head);
    Node *root = sortedDLLtoBST(head, n);
    return root;
}

int main()
{
    Node *root1 = NULL;
    vector<int> preorder1 = {50, 40, 60, 70, -1};
    cout << "Enter data to create BST 1 tree\n";
    takeInput(root1, preorder1);

    Node *root2 = NULL;
    vector<int> preorder2 = {55, 45, 35, 47, 65, -1};
    cout << "Enter data to create BST 2 tree\n";
    takeInput(root2, preorder2);

    cout << "\n BST 1 \n";
    levelorder(root1);

    cout << "\n BST 2 \n";
    levelorder(root2);

    cout << "\n Merged using vector \n";
    Node *root11 = mergeBST1(root1, root2);
    levelorder(root11);

    cout << "\n Merged using DLL \n";
    Node *root22 = mergeBST2(root1, root2);
    levelorder(root22);
    return 0;
}