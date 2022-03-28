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

void iterative_preorder(Node *root)
{
    stack<Node *> stk;

    while (root or !stk.empty())
    {
        if (root)
        {
            cout << root->value << " ";
            stk.emplace(root);
            root = root->left;
        }
        else
        {
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }
}

int main()
{
    Node *root = createTree();

    cout << "Recursive Preorder Traversal\n";
    preorder(root);
    cout << "\n";

    cout << "Iterative Traversal\n";
    iterative_preorder(root);
    cout << "\n";

    return 0;
}