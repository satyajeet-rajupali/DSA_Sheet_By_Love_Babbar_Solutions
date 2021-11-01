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
    //Method-1
    void zigZagTraversal(TreeNode *root);

    // Method-2 (Recursive Approach)
    void zigZagTraversal1(TreeNode *root, int height, bool leftToRight, vector<int> &ans);
    int HeightOfTree(TreeNode *root);
    vector<int> zigZagTraversal1(TreeNode *root);

    // Methtod-3:
    vector<int> zigZagTraversal2(TreeNode *root);
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

    zigZagTraversal(root);

    vector<int> ans = zigZagTraversal1(root);
    cout << "Zig-Zag Traversal using Method-2:\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    vector<int> ans1 = zigZagTraversal2(root);
    cout << "Zig-Zag Traversal using Method-3:\n";
    for (auto it = ans1.begin(); it != ans1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

// Method - 1: Time Complexity: O(n) (Linear Time)
// This method involves the use of two stacks and boolean variable, one of the stacks currentLevel is used
// to store the nodes which are to be printed and gets its nodes from the nextLevel stack which stores the
// nodes in the the order directed by boolean variable.
// Basically, what happens with this is function is it takes the root of the tree as input and stores
// the root in currentLevel stack and reaches to the while which runs and then the root node is popped
// out from the current level and its data gets printed and then depending on the value of the boolean
// variable leftToRight the nodes are pushed into the nextLevel stack and finally when a condition arises
// where the currentLevel is empty inside while loop then the the value of boolean value is complemented
// and a swapping operation is performed between nextLevel and currentLevel stack.
void BinaryTree::zigZagTraversal(TreeNode *root)
{

    if (!root)
    {
        return;
    }

    stack<TreeNode *> currentLevel;
    stack<TreeNode *> nextLevel;

    bool leftToRight = true;

    currentLevel.emplace(root);

    cout << "Zig-Zag Traversal using Method-1:\n";

    while (!currentLevel.empty())
    {

        root = currentLevel.top();
        currentLevel.pop();

        cout << root->value << " ";

        if (leftToRight)
        {

            if (root->left)
            {
                nextLevel.emplace(root->left);
            }

            if (root->right)
            {
                nextLevel.emplace(root->right);
            }
        }
        else
        {

            if (root->right)
            {
                nextLevel.emplace(root->right);
            }

            if (root->left)
            {
                nextLevel.emplace(root->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
    cout << "\n";
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

// In this function recursive call is done to reach to the elements present at different levels and
// insert them into the vector in a direction accordin to leftToRight boolean variable.
void BinaryTree::zigZagTraversal1(TreeNode *root, int height, bool leftToRight, vector<int> &ans)
{
    if (height <= 1 && root)
    {
        ans.push_back(root->value);
    }
    else
    {
        if (leftToRight)
        {
            zigZagTraversal1(root->left, height - 1, leftToRight, ans);
            zigZagTraversal1(root->right, height - 1, leftToRight, ans);
        }
        else
        {
            zigZagTraversal1(root->right, height - 1, leftToRight, ans);
            zigZagTraversal1(root->left, height - 1, leftToRight, ans);
        }
    }
}

// Method - 2: (Recursive Approach)
// In this method, firstly, height is calculated and then for loop is used to loop from 1 to height
// of tree and during every loop function call is made to function
// zizZagTravesal1(root of tree, height, leftToRight, vector) and in every iteration the value of
// leftToRight is complemented.
vector<int> BinaryTree::zigZagTraversal1(TreeNode *root)
{
    vector<int> ans;
    bool leftToRight = true;
    int height = HeightOfTree(root);
    for (int i = 1; i <= height; i++)
    {
        zigZagTraversal1(root, i, leftToRight, ans);
        leftToRight = !leftToRight;
    }
    return ans;
}

// Method-3: Using Deque
vector<int> BinaryTree::zigZagTraversal2(TreeNode *root)
{

    deque<TreeNode *> dq;
    vector<int> v;

    dq.push_back(root);
    v.push_back(root->value);

    int l = 1;

    while (!dq.empty())
    {
        int n = dq.size();
        for (int i = 0; i < n; i++)
        {
            
            if (l % 2 == 0)
            {
                root = dq.back();
                dq.pop_back();
            }
            else
            {
                root = dq.front();
                dq.pop_front();
            }

            if (l % 2 != 0)
            {
                if (root->right)
                {
                    dq.push_back(root->right);
                    v.push_back(root->right->value);
                }
                if (root->left)
                {
                    dq.push_back(root->left);
                    v.push_back(root->left->value);
                }
            }
            else if (l % 2 == 0)
            {
                if (root->left)
                {
                    dq.push_front(root->left);
                    v.push_back(root->left->value);
                }
                if (root->right)
                {
                    dq.push_front(root->right);
                    v.push_back(root->right->value);
                }
            }
            l++;
        }
    }

    return v;
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}
