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

    int LargestSubtreeSum(TreeNode *root);
    int LargestSubtreeSumCalculator(TreeNode *node, int &sum);
    void PreOrderTraversal(TreeNode *root);
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

    cout << "Values in the tree:\n";
    PreOrderTraversal(root);
    cout << "\n";
    cout << "Largest Sum of the Subtree: " << LargestSubtreeSum(root) << "\n";
}

int BinaryTree::LargestSubtreeSumCalculator(TreeNode *node, int &sum)
{

    if (!node)
    {
        return 0;
    }

    int currentSum = node->value + LargestSubtreeSumCalculator(node->left, sum) + LargestSubtreeSumCalculator(node->right, sum);
    sum = max(currentSum, sum);

    return currentSum;
}

int BinaryTree::LargestSubtreeSum(TreeNode *root)
{

    if (!root)
    {
        return 0;
    }

    int sum = INT_MIN;
    LargestSubtreeSumCalculator(root, sum);

    return sum;
}

void BinaryTree::PreOrderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->value << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}