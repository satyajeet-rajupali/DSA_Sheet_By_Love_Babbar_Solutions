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
    void bottomViewUtil(TreeNode *root, int curr_depth, int hd, map<int, pair<int, int>> &m);
    void bottomView(TreeNode *root);
    void bottomView1(TreeNode *root);
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
    bottomView(root);
    bottomView1(root);
}

// Method - 1 (Iterative Method)
// Thie method prints values of the nodes which are visible from the bottom view
// Basically, it takes the root of the tree as input and does a level order traversal
// and it keeps storing the values of the nodes in the map and eventually all gets printed
void BinaryTree::bottomView(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    int hd = 0;
    map<int, int> m;
    queue<TreeNode *> q;

    q.emplace(root);
    root->hd = hd;

    cout << "Bottom View of Elements from Method-1:\n";

    while (q.size())
    {
        root = q.front();
        q.pop();

        hd = root->hd;

        // here it adds new nodes as well as also updates the node which are already present when a new node of the
        // same horizontal distance is encountered.
        m[hd] = root->value;

        if (root->left)
        {
            root->left->hd = hd - 1;
            q.emplace(root->left);
        }

        if (root->right)
        {
            root->right->hd = hd + 1;
            q.emplace(root->right);
        }
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << "\n";
}

// In this function the actual caulculation of Method-2 is performed
void BinaryTree::bottomViewUtil(TreeNode *root, int curr_depth, int hd, map<int, pair<int, int>> &m)
{
    if (!root)
    {
        return;
    }

    // Here, nodes which have a certain hd and never have been encountered are added.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root->value, curr_depth);
    }
    // Here, nodes which are already present in the map gets updated if the current node
    // encountered have the same hd but its current depth is greater.
    else
    {
        if (m[hd].second <= curr_depth)
        {
            m[hd].second = curr_depth;
            m[hd].first = root->value;
        }
    }

    bottomViewUtil(root->left, curr_depth + 1, hd - 1, m);
    bottomViewUtil(root->right, curr_depth + 1, hd + 1, m);
}

// Method - 2 (Recursive Method)
// In this method the map, current depth, horizontal distance from root and root of the tree is
// passed to the function bottomViewUtil and it adds the values of the nodes which are visible
// from bottom to the map and eventually the values gets printed with the help of the loop.
void BinaryTree::bottomView1(TreeNode *root)
{
    map<int, pair<int, int>> mp;
    cout << "Bottom View of Elements from Method-2:\n";

    bottomViewUtil(root, 0, 0, mp);

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->second.first << " ";
    }
    cout << "\n";
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}