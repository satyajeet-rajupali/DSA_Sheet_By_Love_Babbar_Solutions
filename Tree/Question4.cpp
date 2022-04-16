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

void inorder(Node *t)
{
    if (t)
    {
        inorder(t->left);
        cout << t->value << " ";
        inorder(t->right);
    }
}

Node *mirro_tree(Node *root)
{
    queue<Node *> q;
    q.emplace(root);
    Node *temp, *p;

    while (q.size() > 0)
    {
        p = q.front();
        q.pop();

        temp = p->left;
        p->left = p->right;
        p->right = temp;

        if (p->left)
            q.emplace(p->left);

        if (p->right)
            q.emplace(p->right);
    }

    return root;
}

Node *recur_mirror_tree(Node *root)
{
    if (!root)
        return root;
    Node *t = root->left;
    root->left = root->right;
    root->right = t;

    if (root->left)
        recur_mirror_tree(root->left);

    if (root->right)
        recur_mirror_tree(root->right);

    return root;
}

int main()
{
    Node *root = createTree();
    cout << "Before Reversal:\n";
    cout << "Elements in the tree:\n";
    inorder(root);
    cout << "\n";

    Node *rev_tree = recur_mirror_tree(root);

    cout << "After Reversal:\n";
    cout << "Elements in the tree:\n";
    inorder(rev_tree);

    // preorder(root);

    return 0;
}