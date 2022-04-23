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
    Node *newNode(int key);
    Node *binaryTreeToBST(Node *root);
    void inorderBinaryTree(Node *root, vector<int> &nodes);
    void inorderBinarySearchTree(Node *root, vector<int> &nodes, int &i);
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

Node *BST::newNode(int key)
{
    Node *t = new Node;
    t->data = key;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void BST::inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *BST::binaryTreeToBST(Node *root)
{
    if (!root)
        return root;
    vector<int> nodes;
    int i = 0;
    inorderBinaryTree(root, nodes);
    sort(nodes.begin(), nodes.end());
    inorderBinarySearchTree(root, nodes, i);
    return root;
}

void BST::inorderBinaryTree(Node *root, vector<int> &nodes)
{
    if (!root)
        return;
    inorderBinaryTree(root->left, nodes);
    nodes.push_back(root->data);
    inorderBinaryTree(root->right, nodes);
}

void BST::inorderBinarySearchTree(Node *root, vector<int> &nodes, int &i)
{
    if (!root)
        return;
    inorderBinarySearchTree(root->left, nodes, i);
    root->data = nodes[i++];
    inorderBinarySearchTree(root->right, nodes, i);
}

int main()
{
    BST bst;

    bst.root = bst.newNode(1);
    bst.root->left = bst.newNode(2);
    bst.root->right = bst.newNode(3);
    (bst.root->left)->left = bst.newNode(4);

    cout << "Elements in Tree:\n";
    bst.inorder(bst.root);
    cout << "\n";

    Node *root = bst.binaryTreeToBST(bst.root);

    cout << "Elements in Tree:\n";
    bst.inorder(bst.root);

    return 0;
}