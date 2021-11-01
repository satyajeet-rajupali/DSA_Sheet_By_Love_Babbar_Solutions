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
    int createBinaryTree();
    int Diameter(TreeNode *root);
    int Height(TreeNode *node);
    int diameterOpt(TreeNode* root, int *height);
};

BinaryTree::BinaryTree(/* args */)
{
}

BinaryTree::~BinaryTree()
{
}

int BinaryTree::createBinaryTree()
{
    TreeNode *p, *t;
    root = new TreeNode;
    int x;
    queue<TreeNode *> q;


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
    int height  = 0;
    
    return diameterOpt(root, &height);
};



int BinaryTree::Diameter(TreeNode *root)
{
    if(root){
        int lHeight = Height(root->left);
        int rHeight = Height(root->right);

        int lDiameter = Diameter(root->left);
        int rDiameter = Diameter(root->right);

        return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
    }
    return 0;
}

int BinaryTree::Height(TreeNode *root)
{

    if (root)
    {
        return 1 + max(Height(root->left), Height(root->right));
    }
    return 0;
}

int BinaryTree::diameterOpt(TreeNode* root, int* height)
{
    
    int lh = 0, rh = 0;
 
    int ldiameter = 0, rdiameter = 0;
 
    if (root == NULL) {
        *height = 0;
        return 0; // diameter is also 0 
    }
 
    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // rdiameter
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
 
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
 
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main()
{

    int diameter;
    BinaryTree bt;
    diameter = bt.createBinaryTree();

    cout<<"Diameter is: "<<diameter;
    return 0;
}