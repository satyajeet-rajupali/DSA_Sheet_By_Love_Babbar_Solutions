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

    int ConvertToSumTree(TreeNode* root);

    void predOrder(TreeNode* root);

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

    cout<<"Traversal of the tree is: \n";
    predOrder(root);
    cout<<"\n";
    ConvertToSumTree(root);
    cout<<"Traversal of the resultant tree is: \n";
    predOrder(root);

    
}


void BinaryTree::predOrder(TreeNode *root){
    if(root){
        cout<<root->value<<" ";
        predOrder(root->left);
        predOrder(root->right);
    }
}

int BinaryTree::ConvertToSumTree(TreeNode *root){

    if(!root){
        return 0;
    }
    int old_val = root->value;
    root->value = ConvertToSumTree(root->left)  + ConvertToSumTree(root->right);
    return root->value + old_val;
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();

    
    return 0;
}