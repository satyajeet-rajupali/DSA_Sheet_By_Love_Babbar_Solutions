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

    // Binary Tree From String
    TreeNode *BinaryTreeFromString(string str, int si, int ei);
    int ClosingBracketIndex(string str, int si, int ei);

    // Traversal Method
    void preorder(TreeNode *root);
};

BinaryTree::BinaryTree(/* args */) {}

BinaryTree::~BinaryTree() {}

void BinaryTree::preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int BinaryTree::ClosingBracketIndex(string str, int si, int ei)
{
    if (si > ei)
    {
        return -1;
    }

    stack<char> stk;

    for (int i = si; i <= ei; i++)
    {

        if (str[i] == '(')
        {
            stk.emplace(str[i]);
        }
        else if (str[i] == ')')
        {

            if (stk.top() == '(')
            {
                stk.pop();

                if (stk.empty())
                {
                    return i;
                }
            }
        }
    }

    return -1;
}

TreeNode *BinaryTree::BinaryTreeFromString(string str, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(str[si] - '0');
    int index = -1;

    if (si + 1 <= ei && str[si + 1] == '(')
    {
        index = ClosingBracketIndex(str, si + 1, ei);
    }

    if (index != -1)
    {
        root->left = BinaryTreeFromString(str, si + 2, index - 1);
        root->right = BinaryTreeFromString(str, index + 2, ei - 1);
    }

    return root;
}

int main()
{
    BinaryTree tree;
    string entry = "1(2(4)(5))(3(6)(7))";
    TreeNode *root = tree.BinaryTreeFromString(entry, 0, entry.length() - 1);
    tree.preorder(root);

    return 0;
}