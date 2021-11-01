#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    int hd = 0;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
        hd = 0;
    }

    TreeNode(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
        hd = 0;
    }
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree(/* args */);
    ~BinaryTree();
    void createBinaryTree();

    // Boundary Traversal
    bool isLeafNode(TreeNode *root);
    void boundaryTraversal(TreeNode *root, vector<int> &answer);
    void leftNodes(TreeNode *root, vector<int> &answer);
    void rightNodes(TreeNode *root, vector<int> &answer);
    void leafNodes(TreeNode *root, vector<int> &answer);
};

BinaryTree::BinaryTree(/* args */)
{
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::createBinaryTree()
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

    cout << "Boundary Traversal of the tree:\n";
    vector<int> answer;
    boundaryTraversal(root, answer);

    for (auto it : answer)
    {
        cout << it << " ";
    }
    cout << "\n";
}

bool BinaryTree::isLeafNode(TreeNode *node)
{
    if (!node->left && !node->right)
    {
        return true;
    }
    return false;
}

void BinaryTree::boundaryTraversal(TreeNode *root, vector<int> &answer)
{
    answer.push_back(root->value);
    leftNodes(root->left, answer);
    leafNodes(root->left, answer);
    leafNodes(root->right, answer);
    rightNodes(root->right, answer);
}

void BinaryTree::leftNodes(TreeNode *root, vector<int> &answer)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        answer.push_back(root->value);
        leftNodes(root->left, answer);
    }
    else if (root->right)
    {
        answer.push_back(root->value);
        leftNodes(root->right, answer);
    }
}

void BinaryTree::rightNodes(TreeNode *root, vector<int> &answer)
{
    if (!root)
    {
        return;
    }

    if (root->right)
    {
        rightNodes(root->right, answer);
        answer.push_back(root->value);
    }
    else if (root->left)
    {
        rightNodes(root->left, answer);
        answer.push_back(root->value);
    }
}

void BinaryTree::leafNodes(TreeNode *root, vector<int> &answer)
{
    if (!root)
    {
        return;
    }

    leafNodes(root->left, answer);

    if (!root->left && !root->right)
    {
        answer.push_back(root->value);
    }

    leafNodes(root->right, answer);
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}