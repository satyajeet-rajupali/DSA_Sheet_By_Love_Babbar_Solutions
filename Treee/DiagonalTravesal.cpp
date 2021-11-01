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

    // Recursive Method TC: O(NlogN)
    void diagonalPrintUtil(TreeNode *root, int d, map<int, vector<int>> &diagonalPrint);
    void diagonalPrint(TreeNode *root);

    // Iterative Method TC: O(NlogN)
    vector<int> diagonalTraversal(TreeNode *root);

    // TC: O(N)
    vector<vector<int>> diagonalPrint1(TreeNode *root);
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

    diagonalPrint(root);
    vector<int> vec = diagonalTraversal(root);
    cout << "Diagonally Traversed Nodes (Iterative):\n";
    for (auto it : vec)
    {
        cout << it << " ";
    }
    cout << "\n";

    vector<vector<int>> result;
    result = diagonalPrint1(root);
    cout << "Diagonally Traversed Nodes (TC: O(N)):\n";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << "  ";
        cout << endl;
    }
}

void BinaryTree::diagonalPrintUtil(TreeNode *root, int d, map<int, vector<int>> &diagonalPrint)
{
    if (!root)
    {
        return;
    }

    diagonalPrint[d].push_back(root->value);
    diagonalPrintUtil(root->left, d + 1, diagonalPrint);
    diagonalPrintUtil(root->right, d, diagonalPrint);
}

void BinaryTree::diagonalPrint(TreeNode *root)
{
    map<int, vector<int>> diagonalPrintMap;
    diagonalPrintUtil(root, 0, diagonalPrintMap);
    cout << "Diagonally Traversed Nodes (Recursive):\n";
    for (auto it : diagonalPrintMap)
    {
        vector<int> v = it.second;

        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
}

vector<int> BinaryTree::diagonalTraversal(TreeNode *root)
{

    vector<int> diagonalVals;
    queue<TreeNode *> q;

    if (!root)
    {
        return diagonalVals;
    }

    while (root)
    {
        diagonalVals.push_back(root->value);

        if (root->left)
        {
            q.push(root->left);
        }

        if (root->right)
        {
            root = root->right;
        }
        else
        {
            if (!q.empty())
            {
                root = q.front();
                q.pop();
            }
            else
            {
                root = NULL;
            }
        }
    }
    return diagonalVals;
}

vector<vector<int>> BinaryTree::diagonalPrint1(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> q;

    if (!root)
    {
        return result;
    }

    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        vector<int> answer;

        while (size--)
        {
            TreeNode *temp = q.front();
            q.pop();

            while (temp)
            {
                answer.push_back(temp->value);

                if (temp->left)
                {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }

    return result;
}

int main()
{
    BinaryTree tree;
    tree.createBinaryTree();
    return 0;
}