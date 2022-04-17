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

bool isIsomorphic(Node *root1, Node *root2)
{
    // add code here.
    if (!root1 and !root2)
        return true;

    if (!root1 or !root2)
        return false;

    if (root1->data == root2->data)
        return true;

    bool isomorphism = (isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left));
    bool mirrorism = (isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right));

    return isomorphism or mirrorism;
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}