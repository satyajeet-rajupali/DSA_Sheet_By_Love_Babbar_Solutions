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
    Node *root, *root1, *root2;
    BST() { root = nullptr; }

    Node *newNode(int data);

    // To insert elements in the Binary Search Tree (BST).
    void insert(int key);               // Iterative
    Node *rInsert(Node *root, int key); // Recursive

    // To display the elements of Binary Search Tree
    void inorder(Node *root);
    int countPairs(Node *root1, Node *root2, int x);
    void countPairsUtil(Node *root1, Node *root2, int &count, int x);
    bool searchRoot1inRoot2(Node *root2, int key);
};

bool BST::searchRoot1inRoot2(Node *root2, int key)
{
    if (!root2)
        return false;

    if (root2->data == key)
        return true;

    bool x = false;
    bool y = false;

    if (key < root2->data)
        x = searchRoot1inRoot2(root2->left, key);
    else if (key > root2->data)
        y = searchRoot1inRoot2(root2->right, key);
    return x or y;
}

void BST::countPairsUtil(Node *root1, Node *root2, int &count, int x)
{
    if (!root1)
        return;

    countPairsUtil(root1->left, root2, count, x);
    if (searchRoot1inRoot2(root2, x - root1->data))
        count++;
    countPairsUtil(root1->right, root2, count, x);
}

int BST::countPairs(Node *root1, Node *root2, int x)
{
    int count = 0;
    countPairsUtil(root1, root2, count, x);
    return count;
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

    bst.root1 = bst.newNode(1);
    bst.root1->right = bst.newNode(3);
    bst.root1->right->left = bst.newNode(2);

    cout << "Elements in BST1:\n";
    bst.inorder(bst.root1);
    cout << "\n";

    bst.root2 = bst.newNode(3);
    bst.root2->left = bst.newNode(2);
    bst.root2->right = bst.newNode(4);
    bst.root2->left->left = bst.newNode(1);

    cout << "Elements in BST2:\n";
    bst.inorder(bst.root2);
    cout << "\n";

    cout << "Count Pairs: " << bst.countPairs(bst.root1, bst.root2, 4) << "\n";

    return 0;
}