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
    bool checkTreeBalancedOrNot(TreeNode *root, int* height);
    int HeightOfTree(TreeNode *root);
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
    cout << "Height of Tree: " << HeightOfTree(root) << "\n";
    int h = 0;
    if(checkTreeBalancedOrNot(root, &h)){
        cout<<"Tree is balanced"<<"\n";
    } else {
        cout<<"Tree not balanced"<<"\n";
    }
}

int BinaryTree::HeightOfTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return max(HeightOfTree(root->left), HeightOfTree(root->right)) + 1;
    }
}

bool BinaryTree::checkTreeBalancedOrNot(TreeNode *root, int *height)
{
    int lh=0, rh=0, l=0, r=0;

    if(!root){
        *height = 0;
        return 1;
    }

    l = checkTreeBalancedOrNot(root->left, &lh);
    r = checkTreeBalancedOrNot(root->right, &rh);

    *height = (lh > rh ? lh :rh) + 1;

    if(abs(lh-rh>=2)){
        return 0;
    } else {
        return l && r;
    }
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}