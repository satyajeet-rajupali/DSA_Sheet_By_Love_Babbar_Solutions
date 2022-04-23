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
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key);
    Node *search(int key);
};

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

void BST::findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    Node *nKey = search(key);
    Node *p = nKey->left;
    Node *s = nKey->right;

    while (p and p->right)
        p = p->right;

    while (s and s->left)
        s = s->left;

    pre = p;
    suc = s;

    pre ? cout << "Inorder Predecessor: " << pre->data << "\n" : cout << "";
    suc ? cout << "Inorder Successor: " << suc->data << "\n" : cout << "";
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
    int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";
    Node *pre, *suc;
    bst.findPreSuc(bst.root, pre, suc, 30);

    // BST bst1;
    // int arr1[] = {30, 12, 17, 35, 25, 40, 50, 55};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // for (int i = 0; i < n1; i++)
    //     bst1.root = bst1.rInsert(bst1.root, arr1[i]);

    // cout << "Elements in BST(Recursive):\n";
    // bst1.inorder(bst1.root);
    // cout << "\n";

    return 0;
}