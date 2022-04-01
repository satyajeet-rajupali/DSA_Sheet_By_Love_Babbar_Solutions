#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int value, hd;
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
    root->hd = 0;

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
            t->hd = 0;
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
            t->hd = 0;

            p->right = t;
            q.emplace(t);
        }
    }

    return root;
}

void fill_map(Node *root, int hd, int depth, map<int, pair<int, int>> &m)
{
    if (!root)
        return;

    if (m.count(hd) == 0)
    {
        m[hd] = make_pair(root->value, depth);
    }
    else if (m[hd].second <= depth)
    {
        m[hd] = make_pair(root->value, depth);
    }

    fill_map(root->left, hd - 1, depth + 1, m);
    fill_map(root->right, hd + 1, depth + 1, m);
}

void bottomView(Node *root)
{
    map<int, pair<int, int>> m;
    fill_map(root, 0, 0, m);

    cout << "Bottom-View Of Tree:\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->second.first << " ";
    cout << "\n";
}

void bottom_view_using_hd_map(Node *root)
{

    queue<Node *> q;
    map<int, int> m;

    q.emplace(root);

    int hd = 0;
    root->hd = hd;

    while (!q.empty())
    {
        hd = root->hd;

        if (m.count(hd) == 0)
            m[hd] = root->value;
        else
            m[hd] = root->value;

        if (root->left)
        {
            root->left->hd = hd - 1;
            q.emplace(root->left);
        }

        if (root->right)
        {
            root->right->hd = hd + 1;
            q.emplace(root->right);
        }

        q.pop();
        root = q.front();
    }

    cout << "Bottom-View Of Tree:\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->second << " ";
    cout << "\n";
}

int main()
{
    Node *root = createTree();
    bottomView(root);
    bottom_view_using_hd_map(root);

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}