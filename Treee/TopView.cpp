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
    void TopView(TreeNode *root);
    void TopView1(TreeNode *root);
    void fillMap(TreeNode *root, int vertical_distance, int depth, map<int, pair<int, int>> &m);
    void TopView2(TreeNode *root);
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

    TopView(root);
    TopView2(root);
    TopView1(root);

};

// Approach-1: Time Complexity-> O(n)
// Here, We are creating a function which prints the nodes visible from the topview of the tree.
// What it does?
// It finds the left most and right most node on the every level of the tree and stores them into
// stack and vector.
void BinaryTree::TopView(TreeNode *root)
{

    queue<pair<TreeNode *, int>> que; // To hold the nodes and hd.
    stack<int> left;                  // To hold the left visible nodes from TopView.
    vector<int> right;                // To hold the right visible nodes from TopView
    TreeNode *node;

    int hd = 0; // Horizontal Distance from root node
    int l = 0;  // left most distance from root node
    int r = 0;  // right most distance from root node

    right.push_back(root->value);
    que.emplace(make_pair(root, 0));

    while (que.size())
    {
        node = que.front().first;
        hd = que.front().second;
        que.pop();

        if (hd < l)
        {
            left.emplace(node->value);
            l = hd;
        }
        else if (hd > r)
        {
            right.push_back(node->value);
            r = hd;
        }

        if (node->left) // By this we're making sure that no null left child will be stored in the queue.
        {
            que.emplace(make_pair(node->left, hd - 1));
        }

        if (node->right) // By this we're making sure that no null right child will be stored in the queue.
        {
            que.emplace(make_pair(node->right, hd + 1));
        }
    }

    // printing the left node's data in reverse order
    while (left.size())
    {
        cout << left.top() << " ";
        left.pop();
    }

    // finally printing the right node's data
    for (auto x : right)
    {
        cout << x << " ";
    }
}


// Approach-2 :
// Here, What this function doing is, it is creating records of the nodes visited with hghest horizontal distance
// (irrespective of the sign) from the root node at every level and stores in the map.
// Basically, it performs level order traversal starting from the root and it stores the nodes which are at
// highest horizontal distance from root either in left or right direction in the map at every level and
// the distcances are independent of their signs.
void BinaryTree::TopView2(TreeNode *root)
{

    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    map<int, int> m;

    int hd = 0;
    root->hd = hd;
    q.emplace(root);

    cout << "\nApproach - 2:\n";

    while (q.size())
    {
        hd = root->hd;

        if (m.count(hd) == 0)
        {
            m[hd] = root->value;
        }

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

        root = q.front();
        q.pop();
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << "\n";
}



void BinaryTree::fillMap(TreeNode *root, int vertical_distance, int depth, map<int, pair<int, int>> &m)
{
    if (root == nullptr)
    {
        return;
    }

    if (m.count(vertical_distance) == 0)
    {
        m[vertical_distance] = make_pair(root->value, depth);
    }
    else if (m[vertical_distance].second > depth)
    {
        m[vertical_distance] = make_pair(root->value, depth);
    }

    fillMap(root->left, vertical_distance - 1, depth + 1, m);
    fillMap(root->right, vertical_distance + 1, depth + 1, m);
}

// Approach - 3: Time Complexity -> O(nlogn)
// In this approcach we have used recursion but the concept of it still remains the same as 
// Approach 2.
void BinaryTree::TopView1(TreeNode *root)
{
    map<int, pair<int, int>> map;

    fillMap(root, 0, 0, map);

    cout<<"\nApproach - 3:\n";

    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << it->second.second << " ";
    }

    cout << "\n";
}



int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}