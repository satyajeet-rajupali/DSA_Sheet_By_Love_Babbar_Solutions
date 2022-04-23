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
    int kthLargest(Node *root, int k);
    void findKthLargest(Node *root, int k, int &j, int &ans);
};

void BST::findKthLargest(Node *root, int k, int &j, int &ans)
{

    if (!root)
        return;

    findKthLargest(root->right, k, j, ans);
    j++;

    if (j == k)
        ans = root->data;
    findKthLargest(root->left, k, j, ans);
}

int BST::kthLargest(Node *root, int K)
{
    // Your code here
    int ans, j = 0;
    findKthLargest(root, K, j, ans);
    return ans;
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
    int arr[] = {4, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    cout << "Kth largest element: " << bst.kthLargest(bst.root, 2) << "\n";

    return 0;
}