#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int value;
    int hd;
};

Node *createTree()
{
    Node *root = new Node;
    int x;
    cout << "Enter root node:\n";
    cin >> x;
    root->value = x;
    root->hd = 0;
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

void preorder(Node *t)
{
    if (t)
    {
        cout << t->value << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

void top_view_using_hd_map(Node *root)
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

    cout << "Top-View Of Tree:\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->second << " ";
    cout << "\n";
}

void fillmap(Node *root, int d, int l, map<int, pair<int, int>> &mp)
{
    if (!root)
        return;

    if (mp.count(d) == 0) // This step will be performed when d isn't present in mp
        mp[d] = make_pair(root->value, l);
    else if (mp[d].second > l)
        mp[d] = make_pair(root->value, l);

    fillmap(root->left, d - 1, l + 1, mp);
    fillmap(root->right, d + 1, l + 1, mp);
}

void top_view_using_two_variables(Node *root)
{
    map<int, pair<int, int>> mp;
    fillmap(root, 0, 0, mp);

    cout << "Top-View Of Tree:\n";
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second.first << " ";
    cout << "\n";
}

void top_view_using_stack_vector(Node *root)
{
    queue<pair<Node *, int>> q;
    stack<int> stk;
    vector<int> vec;

    Node *p;

    q.emplace(make_pair(root, 0));

    int hd(0), l(0), r(0);

    while (!q.empty())
    {
        p = q.front().first;
        hd = q.front().second;

        if (hd < l)
        {
            stk.push(p->value);
            l = hd;
        }
        else if (hd > r)
        {
            vec.push_back(p->value);
            r = hd;
        }

        if (p->left)
        {
            q.emplace(make_pair(p->left, hd - 1));
        }

        if (p->right)
        {
            q.emplace(make_pair(p->right, hd + 1));
        }
        q.pop();
    }

    cout << "Elements from top-view:\n";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    cout << root->value << " ";

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

int main()
{
    Node *root = createTree();
    // top_view_using_hd_map(root);
    // top_view_using_two_variables(root);

    top_view_using_stack_vector(root);

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}