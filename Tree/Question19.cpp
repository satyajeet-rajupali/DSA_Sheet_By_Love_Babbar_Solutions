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

void postorder(Node *t)
{
    if (t)
    {
        postorder(t->left);
        cout << t->data << " ";
        postorder(t->right);
    }
}

Node *buildTreeFromPreIn(int start, int end, int pre[], int &pindex, unordered_map<int, int> &m)
{
    if (start > end)
        return nullptr;

    Node *root = new Node;
    root->data = pre[pindex++];
    root->left = root->right = nullptr;

    int index = m[root->data];

    root->left = buildTreeFromPreIn(start, index - 1, pre, pindex, m);
    root->right = buildTreeFromPreIn(index + 1, end, pre, pindex, m);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, int> preorder;

    for (int i = 0; i < n; i++)
        preorder[in[i]] = i;

    int pindex = 0;

    return buildTreeFromPreIn(0, n - 1, pre, pindex, preorder);
}

int main()
{
    // Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);
    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};
    int N = 4;
    Node *root = buildTree(inorder, preorder, N);
    cout << "Elements of Tree:\n";
    postorder(root);
    cout << "\n";

    return 0;
}