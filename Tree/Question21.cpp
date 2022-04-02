#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
};

Node *createTree()
{
    Node *root = new Node;
    int x;
    cout << "Enter root node:\n";
    cin >> x;
    root->data = x;
    root->left = nullptr;
    root->right = nullptr;

    queue<Node *> q;
    q.emplace(root);
    Node *t, *p;

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left node of " << p->data << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->data << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            q.emplace(t);
        }
    }

    return root;
}

void preorder(Node *t)
{
    if (t)
    {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

int sum(Node *root)
{
    if (!root)
        return 0;

    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node *root)
{
    // Your code here
    int ls, rs;

    if (!root or (!root->left and !root->right))
        return 1;

    ls = sum(root->left);
    rs = sum(root->right);

    if ((root->data == ls + rs) and isSumTree(root->left) and isSumTree(root->right))
        return 1;
    return 0;
}

int isleaf(Node *root)
{
    if (!root)
        return 0;
    else if (!root->left and !root->right)
        return 1;
    return 0;
}

int isSumTREE(Node *root)
{
    int ls, rs;

    if (!root or isleaf(root))
        return 1;

    if (isSumTREE(root->left) and isSumTREE(root->right))
    {

        if (!root->left)
            ls = 0;
        else if (isSumTREE(root->left))
            ls = root->left->data;
        else
            ls = 2 * (root->left->data);

        if (!root->right)
            rs = 0;
        else if (isSumTREE(root->right))
            rs = root->right->data;
        else
            rs = 2 * (root->right->data);

        return (root->data == (ls + rs));
    }

    return 0;
}

int isSUMTree(Node *root)
{

    if (!root)
        return 0;

    int ls, rs;

    ls = isSUMTree(root->left);
    if (ls == -1)
        return -1;

    rs = isSUMTree(root->right);
    if (rs == -1)
        return -1;

    if (isleaf(root) or (root->data == ls + rs))
        return root->data + ls + rs;
    else
        return -1;
}

int main()
{
    Node *root = createTree();

    if (isSUMTree(root))
        cout << "Sum Tree\n";
    else
        cout << "Not SumTree\n";

    return 0;
}