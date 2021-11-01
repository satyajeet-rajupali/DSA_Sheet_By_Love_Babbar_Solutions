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
    vector<int> LevelOrder(TreeNode *node);
    vector<int> leftView(TreeNode *root, int cur_node, int &prev_level);
    vector<int> rightView(TreeNode *root, int cur_node, int &prev_level);
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
    int val = 0;

    return leftView(root, 1, val);
};



// For the Left View of the Tree
vector<int> BinaryTree::leftView(TreeNode *root, int cur_level, int &prev_level)
{
    static vector<int> v;
    cout << "I am working"
         << "\n";

    if (root)
    {
        if (cur_level > prev_level)
        {
            v.push_back(root->value);
            cout << "I am working pushing value" << root->value << "\n";
            prev_level = cur_level;
        }

        cout << "I am working left"
             << " prev_level: " << prev_level << " cur_level: " << cur_level << "\n";
        leftView(root->left, cur_level + 1, prev_level);

        cout << "I am working right "
             << " prev_level: " << prev_level << " cur_level: " << cur_level << "\n";

        leftView(root->right, cur_level + 1, prev_level);
    }

    return v;
}


// For the Right View of Tree
vector<int> BinaryTree::rightView(TreeNode *root, int cur_level, int &prev_level)
{
    static vector<int> v;
    cout << "I am working"
         << "\n";

    if (root)
    {
        if (cur_level > prev_level)
        {
            v.push_back(root->value);
            cout << "I am working pushing value" << root->value << "\n";
            prev_level = cur_level;
        }

        cout << "I am working left"
             << " prev_level: " << prev_level << " cur_level: " << cur_level << "\n";
        leftView(root->right, cur_level + 1, prev_level);

        cout << "I am working right "
             << " prev_level: " << prev_level << " cur_level: " << cur_level << "\n";

        leftView(root->left, cur_level + 1, prev_level);
    }

    return v;
}

int main()
{

    vector<int> vec;
    BinaryTree bt;
    vec = bt.createBinaryTree();
    cout << "size of vec:" << vec.size() << "\n";

    if (vec.size() == 0)
    {
        cout << "Size of vector is 0;";
    }

    cout << "Elements in vector\n";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}