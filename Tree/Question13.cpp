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

bool label = true;
int isBalanced(Node *root)
{
    //  Your Code here
    if (!root)
        return 0;
    else
    {
        int x = isBalanced(root->left);
        int y = isBalanced(root->right);

        if (abs(x - y) > 1)
            label = false;

        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
}

int main()
{
    Node *root = createTree();

    isBalanced(root);
    if (label)
        cout << "Tree is balanced\n";
    else
        cout << "Tree isn't balanced\n";

    return 0;
}