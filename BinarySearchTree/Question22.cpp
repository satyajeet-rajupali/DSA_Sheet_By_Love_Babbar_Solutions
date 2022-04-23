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

    void storeInorder(Node *root, vector<Node *> &nodes);
    void FlattenBSTtoList(Node *root); // With SC: O(N)
    void FlattenBSTToListUsingInorder(Node *p, Node *&prev);
    Node *convertToList(vector<Node *> &nodes);
    void displayList(Node *root);
};

void BST::FlattenBSTToListUsingInorder(Node *p, Node *&prev)
{
    if (!p)
        return;

    FlattenBSTToListUsingInorder(p->left, prev);
    if (prev)
    {
        prev->right = p;
        prev->right->left = prev;
    }
    prev = p;
    FlattenBSTToListUsingInorder(p->right, prev);
}

void BST::displayList(Node *p)
{
    cout << "Elements in the list:\n";
    while (p)
    {
        cout << p->data << " ";
        p = p->right;
    }
    cout << "\n";
}

Node *BST::newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void BST::storeInorder(Node *p, vector<Node *> &nodes)
{
    if (!p)
        return;

    storeInorder(p->left, nodes);
    nodes.push_back(p);
    storeInorder(p->right, nodes);
}

Node *BST::convertToList(vector<Node *> &nodes)
{
    Node *r = nullptr;
    r = nodes[0];
    Node *p = r;

    for (int i = 1; i < nodes.size(); i++)
    {
        Node *t = nodes[i];
        t->left = r;
        r->right = t;
        r = r->right;
    }
    return p;
}

// With SC: O(N)
void BST::FlattenBSTtoList(Node *p)
{
    if (!p)
        return;
    vector<Node *> nodes;
    storeInorder(p, nodes);
    Node *l = convertToList(nodes);
    displayList(l);
    // cout << "Elements in Tree:\n";
    // // inorder(l);
    // cout << "\n";
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
    int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    // bst.FlattenBSTtoList(bst.root);
    Node *prev = nullptr;
    bst.FlattenBSTToListUsingInorder(bst.root, prev);
    bst.displayList(bst.root);

    return 0;
}