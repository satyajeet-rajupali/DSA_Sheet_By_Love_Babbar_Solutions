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

    // Deletion function utilities and Deletetion function itself
    Node *inorderSuccessor(Node *root);
    Node *inorderPredecessor(Node *root);
    Node *Delete(Node *root, int &key);
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

Node *BST::inorderPredecessor(Node *root)
{
    if (!root)
        return nullptr;

    while (root and root->right)
        root = root->right;

    return root;
}

Node *BST::inorderSuccessor(Node *root)
{
    while (root and root->left)
        root = root->left;

    return root;
}

Node *BST::Delete(Node *p, int &key)
{
    Node *q;
    if (!p)
        return nullptr;

    if (!p->left and !p->right)
    {

        if (root == p)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->data)
        p->left = Delete(p->left, key);
    else if (key > p->data)
        p->right = Delete(p->right, key);
    else
    {
        q = inorderSuccessor(p->right);
        p->data = q->data;
        p->right = Delete(p->right, q->data);
    }

    return p;
}

int main()
{
    BST bst;
    int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST pre Deletion:\n";
    bst.inorder(bst.root);
    cout << "\n";
    int key = 30;
    Node *node = bst.Delete(bst.root, key);

    cout << "Elements in BST post Deletion:\n";
    bst.inorder(bst.root);
    cout << "\n";

    return 0;
}