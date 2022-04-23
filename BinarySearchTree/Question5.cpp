#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node *next;
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
    void populateNext(Node *root);
    void populateNextUtil(Node *root, Node *&prev);
    Node *newNode(int key);
    void display(Node *root);
};

void BST::display(Node *root)
{
    cout << "\nElements in tree:\n";
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n";
}

void BST::populateNext(Node *root)
{
    // code here
    Node *prev = nullptr;
    populateNextUtil(root, prev);
    display(root);
}

void BST::populateNextUtil(Node *root, Node *&prev)
{
    if (!root)
        return;

    populateNextUtil(root->left, prev);
    if (prev != nullptr)
        prev->next = root;
    prev = root;
    populateNextUtil(root->right, prev);
}

Node *BST::newNode(int key)
{
    Node *t = new Node;
    t->data = key;
    t->left = nullptr;
    t->right = nullptr;
    Node *r = new Node;
    r->data = -1;
    r->left = r->right = nullptr;
    t->next = r;
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
    bst.root = bst.newNode(30);
    bst.root->left = bst.newNode(15);
    bst.root->right = bst.newNode(50);

    (bst.root->left)->left = bst.newNode(10);
    (bst.root->left)->right = bst.newNode(20);

    (bst.root->right)->left = bst.newNode(40);
    (bst.root->right)->right = bst.newNode(60);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    bst.populateNext(bst.root);

    return 0;
}