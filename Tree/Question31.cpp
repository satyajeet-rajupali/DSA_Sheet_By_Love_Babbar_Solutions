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

Node *lca(Node *root, int n1, int n2)
{
    if (!root or root->data == n1 or root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (!left)
        return right;
    else if (!right)
        return left;
    else
        return root;
}

int findlevel(Node *root, int k, int level)
{
    if (!root)
        return -1;
    if (root->data == k)
        return level;

    int left = findlevel(root->left, k, level + 1);
    if (left == -1)
        return findlevel(root->right, k, level + 1);

    return left;
}

int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *LCA = lca(root, a, b);

    int d1 = findlevel(LCA, a, 0);
    int d2 = findlevel(LCA, b, 0);

    return d1 + d2;
}

int main()
{
    Node *root = createTree();
    int n1 = 4, n2 = 6;

    cout << "Min Dist: " << findDist(root, n1, n2) << "\n";

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}