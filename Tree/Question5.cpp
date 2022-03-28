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

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

void iterative_traversal(Node *root)
{
    stack<Node *> stk;
    Node *p;
    while (root or !stk.empty())
    {
        if (root)
        {
            stk.emplace(root);
            root = root->left;
        }
        else
        {
            root = stk.top();
            stk.pop();
            cout << root->value << " ";
            root = root->right;
        }
    }
}

int main()
{
    Node *root = createTree();
    cout << "Recusive Inorder Traversal:\n";
    inorder(root);
    cout << "\n";

    cout << "Iterative Inorder Traversal:\n";
    iterative_traversal(root);
    cout << "\n";

    return 0;
}