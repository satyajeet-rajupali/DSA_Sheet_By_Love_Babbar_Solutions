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
    Node *post_order(int pre[], int size);
    void postorder(Node *root);
};

void BST::postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
Node *BST::newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

Node *BST::post_order(int pre[], int size)
{
    // code here
    stack<Node *> stk;
    Node *root, *p, *t;
    int i = 0;

    root = new Node;
    root->data = pre[i++];
    root->left = nullptr;
    root->right = nullptr;
    p = root;
    // stk.emplace(root);

    while (i < size)
    {

        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            stk.emplace(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data and pre[i] < (stk.empty() ? INT_MAX : stk.top()->data))
            {
                t = new Node;
                t->data = pre[i++];
                t->left = nullptr;
                t->right = nullptr;
                p->right = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }

    return root;
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
    int arr[] = {40, 30, 32, 35, 80, 90, 100, 120};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = bst.post_order(arr, n);

    cout << "Elements in BST:\n";
    bst.postorder(root);
    cout << "\n";

    return 0;
}