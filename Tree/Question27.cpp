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

int largestSubtreeSum(Node *root, int &res)
{
    if (!root)
        return 0;

    int x = largestSubtreeSum(root->left, res);
    int y = largestSubtreeSum(root->right, res);

    int temp = x + y + root->data;
    res = max(res, temp);

    return temp;
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);
    int res = INT_MIN;
    int ans = largestSubtreeSum(root, res);
    cout << "Largest Subtree Sum: " << ans << "\n";

    return 0;
}