#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
};

class NodeValue
{
public:
    int maxVal, minVal, maxSize;
    NodeValue(int minVal, int maxVal, int maxSize)
    {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
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
    int largestBst(Node *root);
    NodeValue largestBstUtil(Node *root);
};

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

NodeValue BST::largestBstUtil(Node *root)
{
    if (!root)
        return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = largestBstUtil(root->left);
    auto right = largestBstUtil(root->right);

    if (left.maxVal < root->data and root->data > right.minVal)
        return NodeValue(min(root->data, left.minVal), max(root->data, right.maxVal), left.maxSize + right.maxSize + 1);

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int BST::largestBst(Node *root)
{
    // Your code here
    return largestBstUtil(root).maxSize;
}

int main()
{
    BST bst;
    bst.root;
    // int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    //     bst.insert(arr[i]);

    // cout << "Elements in BST(Iterative):\n";
    // bst.inorder(bst.root);
    // cout << "\n";

    return 0;
}