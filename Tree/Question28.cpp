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
int getMaxGrandPC(Node *root, map<Node *, int> &mp);
int getMaxUtil(Node *root, map<Node *, int> &mp);

int getMaxGrandPC(Node *root, map<Node *, int> &mp)
{
    if (!root)
        return 0;

    int sum = 0;

    if (root->left)
        sum += (getMaxUtil(root->left->left, mp) + getMaxUtil(root->left->right, mp));

    if (root->right)
        sum += (getMaxUtil(root->right->left, mp) + getMaxGrandPC(root->right->right, mp));

    return sum;
}

int getMaxUtil(Node *root, map<Node *, int> &mp)
{
    if (!root)
        return 0;

    if (mp.find(root) != mp.end())
        return mp[root];

    int incl = root->data + getMaxGrandPC(root, mp);

    int excl = getMaxUtil(root->left, mp) + getMaxUtil(root->right, mp);

    mp[root] = max(incl, excl);

    return mp[root];
}

int getMax(Node *root)
{
    if (!root)
        return 0;
    map<Node *, int> mp;
    return getMaxUtil(root, mp);
}

// Using pair

pair<int, int> getMaxSumTreeNoAdjacentNodes(Node *root)
{

    if (!root)
    {
        pair<int, int> emp(0, 0);
        return emp;
    }

    pair<int, int> sum1 = getMaxSumTreeNoAdjacentNodes(root->left);
    pair<int, int> sum2 = getMaxSumTreeNoAdjacentNodes(root->right);
    pair<int, int> sum;

    sum.first = root->data + sum1.second + sum2.second;

    sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);

    return sum;
}

int getMaxSumTreeNoAdjacentNodesUtil(Node *root)
{

    if (!root)
        return 0;

    pair<int, int> ans = getMaxSumTreeNoAdjacentNodes(root);
    return max(ans.first, ans.second);
}

unordered_map<Node *, int> mp;
int getMaxSumTreeNoAdjacentNodesUsingDP(Node *root)
{
    if (!root)
        return 0;

    if (mp.find(root) != mp.end())
        return mp[root];

    int incl = root->data;

    if (root->left)
    {
        incl += (getMaxSumTreeNoAdjacentNodesUsingDP(root->left->left) +
                 getMaxSumTreeNoAdjacentNodesUsingDP(root->left->right));
    }

    if (root->right)
    {
        incl += (getMaxSumTreeNoAdjacentNodesUsingDP(root->right->left) +
                 getMaxSumTreeNoAdjacentNodesUsingDP(root->right->right));
    }

    int excl = getMaxSumTreeNoAdjacentNodesUsingDP(root->left) +
               getMaxSumTreeNoAdjacentNodesUsingDP(root->right);

    mp[root] = max(incl, excl);
    return mp[root];
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);
    cout << "Max Sum: " << getMaxSumTreeNoAdjacentNodesUsingDP(root) << "\n";

    return 0;
}