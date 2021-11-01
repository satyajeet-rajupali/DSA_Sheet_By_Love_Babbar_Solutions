#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree(/* args */);
    ~BinaryTree();
    vector<int> createBinaryTree();
    void PreOrder(TreeNode *node);
    vector<int> reverseLevelOrder(TreeNode *node);
};

BinaryTree::BinaryTree(/* args */)
{
}

BinaryTree::~BinaryTree()
{
}

vector<int> BinaryTree::createBinaryTree()
{
    TreeNode *p, *t;
    root = new TreeNode;
    int x;
    queue<TreeNode *> q;
    vector<int> v;

    cout << "Enter the root value for the tree:\n";
    cin >> x;
    root->value = x;
    root->left = root->right = NULL;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter the value of left child of " << p->value << ":\n";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode;
            t->value = x;
            t->left = t->right = NULL;
            p->left = t;
            q.push(t);
        }

        cout << "Enter the value of right child of " << p->value << ":\n";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode;
            t->value = x;
            t->left = t->right = NULL;
            p->right = t;
            q.push(t);
        }
    }

    v = reverseLevelOrder(root);
    return v;
};

vector<int> BinaryTree::reverseLevelOrder(TreeNode *node)
{

    vector<int> v;
    queue<TreeNode *> q;
    stack<TreeNode *> stk;

    q.emplace(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        stk.emplace(node);

        if (node->right)
        {
            q.emplace(node->right);
        }

        if (node->left)
        {
            q.emplace(node->left);
        }
    }

    while (!stk.empty())
    {
        node = stk.top();
        stk.pop();
        v.push_back(node->value);
    }

    return v;
}

int main()
{

    vector<int> vec;
    BinaryTree bt;
    vec = bt.createBinaryTree();

    cout << "Elements in vector\n";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}