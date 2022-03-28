#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int value;
};

Node *createTree()
{
    Node *root = new Node;
    int x;
    cout << "Enter root node:\n";
    cin >> x;
    root->value = x;
    root->left = nullptr;
    root->right = nullptr;

    queue<Node *> q;
    q.emplace(root);
    Node *t, *p;

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left node of " << p->value << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->value = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->value << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->value = x;
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
        cout << t->value << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

void reverseLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<int> stk;
    Node *t;
    q.emplace(root);

    while (!q.empty())
    {
        t = q.front();
        q.pop();

        stk.emplace(t->value);

        if (t->left)
            q.emplace(t->left);

        if (t->right)
            q.emplace(t->right);
    }

    while (stk.size() > 0)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);

    cout << "Reverse Level Order Traversal:\n";
    reverseLevelOrderTraversal(root);
    cout << "\n";

    return 0;
}