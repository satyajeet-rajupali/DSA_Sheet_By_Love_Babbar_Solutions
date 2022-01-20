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

    // Method-1  TC: O(N^2)
    int isSumTree(TreeNode *root);
    int sum(TreeNode *root);
    void predOrder(TreeNode *root);

    // Method-2 TC: O(N)
    int isSumTree1(TreeNode *root);
    int isLeaf(TreeNode *root);
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

    if (isSumTree(root))
    {
        cout << "Sum Tree"
             << "\n";
    }
    else
    {
        cout << "Not Sum Tree"
             << "\n";
    }
}

// Method-1 Implementation
int BinaryTree::sum(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    return sum(root->left) + root->value + sum(root->right);
}

void BinaryTree::predOrder(TreeNode *root){
    if(root){
        cout<<root->value<<" ";
        predOrder(root->left);
        predOrder(root->right);
    }
}

int BinaryTree::isSumTree(TreeNode *root)
{
    int ls, rs;
    if (!root || (!root->left && !root->right))
    {
        return 1;
    }

    ls = sum(root->left);
    rs = sum(root->right);

    if (root->value == ls + rs && isSumTree(root->left) && isSumTree(root->right))
    {
        return 1;
    }

    return 0;
}

// Method-2 Implementation
int BinaryTree::isLeaf(TreeNode *node){
    if(!node){
        return 0;
    }

    if(!node->left && !node->right){
        return 1;
    }
    return 0;
}

int BinaryTree::isSumTree1(TreeNode *root){
    int ls, rs;

    if(root|| isLeaf(root)){
        return 1;
    }

    if(isSumTree1(root->left) && isSumTree1(root->right)){
        if(!root->left){
            ls = 0;
        } else if(isLeaf(root->left)){
            ls = root->left->value;
        } else {
            ls = 2*root->left->value;
        }

        if(!root->right){
            ls = 0;
        } else if(isLeaf(root->right)){
            ls = root->right->value;
        } else {
            ls = 2*root->right->value;
        }

        return root->value == ls + rs;
    }

    return 0;
}

int main()
{
    BinaryTree tree;
    // tree.createBinaryTree();
    TreeNode *node = new TreeNode(44);
    node->left = new TreeNode(9);
    node->right = new TreeNode(13);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->right->left = new TreeNode(7);
    node->right->right = new TreeNode(6);

    tree.predOrder(node);
    cout<<"\n";

    if (tree.isSumTree(node))
    {
        cout << "Sum Tree"
             << "\n";
    }
    else
    {
        cout << "Not Sum Tree"
             << "\n";
    }

    if (tree.isSumTree1(node))
    {
        cout << "Sum Tree"
             << "\n";
    }
    else
    {
        cout << "Not Sum Tree"
             << "\n";
    }

    return 0;
}