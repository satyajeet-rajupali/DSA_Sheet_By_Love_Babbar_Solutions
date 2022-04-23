#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
};

class BST
{
public:
    Node *root;
    BST() { root = nullptr; }

    // To insert elements in the Binary Search Tree (BST).
    void insert(int key);               // Iterative
    Node *rInsert(Node *root, int key); // Recursive

    // To display the elements of Binary Search Tree
    void inorder(Node *root);
    void createTreeFromPreorderTraversal(int preorder[], int n);
};

void BST::insert(int key)
{
    Node *p, *q, *t;
    if (!root)
    {
        t = new Node;
        t->data = key;
        t->left = nullptr;
        t->right = nullptr;
        root = t;
        return;
    }
    p = root;
    while (p)
    {
        q = p;

        if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
        else
            return;
    }

    t = new Node;
    t->data = key;
    t->left = t->right = nullptr;

    if (key < q->data)
        q->left = t;
    else if (key > q->data)
        q->right = t;

    return;
}

Node *BST::rInsert(Node *root, int key)
{
    Node *t;
    if (!root)
    {
        t = new Node;
        t->data = key;
        t->left = nullptr;
        t->right = nullptr;
        return t;
    }

    if (key < root->data)
        root->left = rInsert(root->left, key);
    else if (key > root->data)
        root->right = rInsert(root->right, key);

    return root;
}

void BST::inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BST::createTreeFromPreorderTraversal(int preorder[], int n)
{
    stack<Node *> stk;
    Node *t, *p;
    int i = 0;

    t = new Node;
    t->data = preorder[i++];
    t->left = nullptr;
    t->right = nullptr;
    root = t;
    stk.emplace(root);
    p = root;

    while (i < n)
    {
        if (preorder[i] < p->data)
        {
            t = new Node;
            t->data = preorder[i++];
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            p = t;
            stk.emplace(p);
        }
        else
        {
            if ((preorder[i] > root->data) and (preorder[i] < (stk.empty() ? INT_MAX : stk.top()->data)))
            {
                t = new Node;
                t->data = preorder[i++];
                t->left = nullptr;
                t->right = nullptr;
                p->right = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{
    BST bst;
    int preorder[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    bst.createTreeFromPreorderTraversal(preorder, n);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    return 0;
}