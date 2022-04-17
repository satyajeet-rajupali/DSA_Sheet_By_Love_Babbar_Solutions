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

Node *temp = nullptr;
Node *kthAncestor(Node *root, int node, int &k)
{
    if (!root)
        return nullptr;

    if (root->data == node or (temp = kthAncestor(root->left, node, k)) or
        (temp = kthAncestor(root->right, node, k)))
    {

        if (k > 0)
            k--;
        else if (k == 0)
        {
            cout << "Kth Ancestor: " << root->data;
            return nullptr;
        }
        return root;
    }
}

int main()
{
    Node *root = createTree();
    int k = 2;
    kthAncestor(root, 7, k);

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}