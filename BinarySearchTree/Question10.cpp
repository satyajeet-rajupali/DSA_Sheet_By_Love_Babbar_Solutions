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

    // To insert elements in the Binary Search Tree (BST).
    void insert(int key);               // Iterative
    Node *rInsert(Node *root, int key); // Recursive

    // To display the elements of Binary Search Tree
    void inorder(Node *root);

    Node *newNode(int data);

    Node *mergeBST(Node *root1, Node *root2, int m, int n);
    void storeInorder(Node *root, vector<int> &nodes);
    void merge(vector<int> &three, vector<int> &one, vector<int> &two);

    Node *sortedArrayToBalancedBST(vector<int> &three, int m, int n);
};

Node *BST::newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}

void BST::storeInorder(Node *p, vector<int> &nodes)
{
    if (!p)
        return;

    storeInorder(p->left, nodes);
    nodes.push_back(p->data);
    storeInorder(p->right, nodes);
}

Node *BST::sortedArrayToBalancedBST(vector<int> &three, int m, int n)
{
    if (m > n)
        return nullptr;

    int mid = (m + n) / 2;
    Node *p = new Node;
    p->data = three[mid];

    p->left = sortedArrayToBalancedBST(three, m, mid - 1);
    p->right = sortedArrayToBalancedBST(three, mid + 1, n);

    return p;
}

void BST::merge(vector<int> &three, vector<int> &one, vector<int> &two)
{
    int m = one.size();
    int n = two.size();

    int i(0), j(0), k(0);

    while (i < m and j < n)
    {
        if (one[i] < two[j])
        {
            three.push_back(one[i]);
            i++;
        }
        else if (one[i] > two[j])
        {
            three.push_back(two[j]);
            j++;
        }
        k++;
    }

    while (i < m)
    {
        three.push_back(one[i]);
        i++;
        k++;
    }

    while (j < n)
    {
        three.push_back(two[j]);
        j++;
        k++;
    }
}

Node *BST::mergeBST(Node *root1, Node *root2, int m, int n)
{
    if (!root1 and !root2)
        return nullptr;

    if (!root1 and root2)
        return root2;

    if (root1 and !root2)
        return root1;

    vector<int> one;
    storeInorder(root1, one);

    vector<int> two;
    storeInorder(root2, two);

    vector<int> three;
    merge(three, one, two);

    return sortedArrayToBalancedBST(three, 0, three.size()-1);
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
    // int arr[] = {30, 12, 17, 35, 25, 40, 50, 55};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    //     bst.insert(arr[i]);

    // cout << "Elements in BST(Iterative):\n";
    // bst.inorder(bst.root);
    // cout << "\n";

    // Tree-1
    bst.root1 = bst.newNode(100);
    bst.root1->left = bst.newNode(50);
    bst.root1->right = bst.newNode(300);

    (bst.root1->left)->left = bst.newNode(20);
    (bst.root1->left)->right = bst.newNode(70);

    cout << "Elements in Tree-1:\n";
    bst.inorder(bst.root1);
    cout << "\n";

    // Tree-2
    bst.root2 = bst.newNode(80);
    bst.root2->left = bst.newNode(40);
    bst.root2->right = bst.newNode(120);

    cout << "Elements in Tree-2:\n";
    bst.inorder(bst.root2);
    cout << "\n";

    // bst.root = bst.mergeBST(bst.root1, bst.root2, 5, 3);

    cout << "Elements in Merged Tree:\n";
    bst.inorder(bst.mergeBST(bst.root1, bst.root2, 5, 3));
    cout << "\n";

    return 0;
}