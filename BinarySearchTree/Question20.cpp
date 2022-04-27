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

    Node *newNode(int data);

    // To insert elements in the Binary Search Tree (BST).
    void insert(int key);               // Iterative
    Node *rInsert(Node *root, int key); // Recursive

    // To display the elements of Binary Search Tree
    void inorder(Node *root);
    bool isDeadEnd(Node *root);
    bool isDeadEndUtil(Node *root, int min, int max);
};

bool BST::isDeadEndUtil(Node *root, int min, int max)
{
    if (!root)
        return false;
    cout << "Working-2\n";

    if (min == max)
        return true;

    int val = root->data;
    bool x = isDeadEndUtil(root->left, min, root->data - 1);
    bool y = isDeadEndUtil(root->right, root->data + 1, max);

    cout << "Working-3\n";

    return (x or y);
}

bool BST::isDeadEnd(Node *root)
{
    // Your code here
    if (!root)
        cout << "root\n";
    cout << "Working-1\n";
    return isDeadEndUtil(root, 1, INT_MAX);
}

Node *BST::newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

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

int main()
{
    BST bst;
    bst.root = bst.newNode(8);
    bst.root->left = bst.newNode(7);
    bst.root->right = bst.newNode(10);

    bst.root->left->left = bst.newNode(2);

    bst.root->right->left = bst.newNode(9);
    bst.root->right->right = bst.newNode(13);

    Node *root = bst.root;

    cout << "Elements in BST:\n";
    bst.inorder(root);
    cout << "\n";

    if (bst.isDeadEnd(root))
        cout << "Dead End Present!\n";
    else
        cout << "Dead End Not Present!\n";

    return 0;
}