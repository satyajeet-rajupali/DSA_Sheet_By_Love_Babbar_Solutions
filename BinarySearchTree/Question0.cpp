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
    Node *rInsert(Node *root, int key);
    void rInsert(int key);
    void insert(int key);

    // To display the elements of Binary Search Tree
    void inorder();
    void inorder(Node *root);

    // To search in a BST
    Node *search(int key);
    Node *rSearch(Node *root, int key);
    void rSearch(int key);
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

void BST::rInsert(int key)
{
    root = rInsert(root, key);
}

void BST::inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BST::inorder()
{
    inorder(root);
}

Node *BST::search(int key)
{
    if (!root)
        return nullptr;
    Node *q = root;
    while (q)
    {
        if (q->data == key)
            return q;

        if (key < q->data)
            q = q->left;
        else if (key > q->data)
            q = q->right;
    }
    return nullptr;
}

Node *BST::rSearch(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (root->data == key)
        return root;

    if (key < root->data)
        return rSearch(root->left, key);
    else if (key > root->data)
        return rSearch(root->right, key);
}

int main()
{
    BST bst;
    int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    BST bst1;
    int arr1[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < n1; i++)
        bst1.rInsert(arr1[i]);

    cout << "Elements in BST(Recursive):\n";
    bst1.inorder(bst1.root);
    cout << "\n";

    cout << "Found element (Iterative) " << (bst.search(35))->data << ".\n";
    cout << "Found element (Recursive) " << (bst1.rSearch(bst1.root, 35))->data << ".\n";

    return 0;
}