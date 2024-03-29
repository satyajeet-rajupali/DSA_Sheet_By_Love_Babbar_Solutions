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

void left_view(Node *root, int cur_level, int &prev_level)
{
    if (root)
    {
        if (cur_level > prev_level)
        {
            cout << root->value << " ";
            prev_level = cur_level;
        }
        left_view(root->left, cur_level + 1, prev_level);
        left_view(root->right, cur_level + 1, prev_level);
    }
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root)
    cout << "Left View of the Tree:\n";
    int lv = 0;
    left_view(root, 1, lv);
    cout << "\n";

    return 0;
}