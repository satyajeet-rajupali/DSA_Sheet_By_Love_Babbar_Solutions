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

    Node *newNode(int key);

    // To insert elements in the Binary Search Tree (BST).
    void insert(int key);               // Iterative
    Node *rInsert(Node *root, int key); // Recursive

    // To display the elements of Binary Search Tree
    void inorder(Node *root);

    bool isBST(Node *root);
    bool isBSTUtil1(Node *root, Node *l, Node *r);
    bool isBSTUtil2(Node *root, Node *&prev);
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

Node *BST::newNode(int key)
{
    Node *t = new Node;
    t->data = key;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

bool BST::isBSTUtil1(Node *root, Node *l, Node *r)
{
    if (!root)
        return true;
    if (l and (root->data <= l->data))
        return false;
    if (r and (root->data >= r->data))
        return false;

    return (isBSTUtil1(root->left, l, root) and isBSTUtil1(root->right, root, r));
}

bool BST::isBSTUtil2(Node *root, Node *&prev)
{
    if (!root)
        return true;

    if (!isBSTUtil2(root->left, prev))
        return false;

    if (prev and root->data <= prev->data)
        return false;

    prev ? cout << prev->data << "\n" : cout << "\n";

    prev = root;

    return isBSTUtil2(root->right, prev);
}

bool BST::isBST(Node *root)
{
    if (!root)
        return true;
    Node *prev = nullptr;
    return isBSTUtil2(root, prev);
}

int main()
{
    BST bst;
    // int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    //     bst.insert(arr[i]);

    // cout << "Elements in BST(Iterative):\n";
    // bst.inorder(bst.root);
    // cout << "\n";

    // BST bst1;
    // int arr1[] = {30, 12, 17, 35, 25, 40, 50, 55};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // for (int i = 0; i < n1; i++)
    //     bst1.root = bst1.rInsert(bst1.root, arr1[i]);

    // cout << "Elements in BST(Recursive):\n";
    // bst1.inorder(bst1.root);
    // cout << "\n";

    // bst.root = bst.newNode(2);
    // bst.root->right = bst.newNode(7);
    // (bst.root->right)->right = bst.newNode(6);
    // ((bst.root->right)->right)->right = bst.newNode(5);
    // (((bst.root->right)->right)->right)->right = bst.newNode(9);
    // ((((bst.root->right)->right)->right)->right)->right = bst.newNode(2);
    // (((((bst.root->right)->right)->right)->right)->right)->right = bst.newNode(6);

    bst.root = bst.newNode(2);
    bst.root->left = bst.newNode(1);
    bst.root->right = bst.newNode(3);

    cout << "Elements in the tree:\n";
    bst.inorder(bst.root);
    cout << "\n";

    if (bst.isBST(bst.root))
        cout << "Is BST\n";
    else
        cout << "Isn't BST\n";

    return 0;
}