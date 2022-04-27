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
    int countNodes(Node *root);
    int median(Node *root);
};

int BST::median(Node *root)
{
    int median = 0;
    Node *cur = root;
    Node *follower, *prev;

    int count = countNodes(root);
    int currCount = 0;

    while (cur)
    {

        if (!cur->left)
        {
            currCount++;

            if (count % 2 != 0 and currCount == ((count + 1) / 2))
                return follower->data;
            else if (count % 2 == 0 and currCount == ((count / 2) + 1))
                return (follower->data + cur->data) / 2;

            follower = cur;

            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right and prev->right != cur)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                follower = prev;

                currCount++;

                if (count % 2 != 0 and currCount == ((count + 1) / 2))
                    return cur->data;
                else if (count % 2 == 0 and currCount == ((count / 2) + 1))
                    return (follower->data + cur->data) / 2;

                follower = cur;
                cur = cur->right;
            }
        }
    }

    return median;
}

int BST::countNodes(Node *root)
{
    int count = 0;

    Node *cur = root;

    while (cur)
    {
        if (!cur->left)
        {
            count++;
            cur = cur->right;
        }
        else
        {
            Node *follower = cur->left;
            while (follower->right and follower->right != cur)
                follower = follower->right;

            if (!follower->right)
            {
                follower->right = cur;
                cur = cur->left;
            }
            else
            {
                follower->right = nullptr;
                count++;
                cur = cur->right;
            }
        }
    }
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
    int arr[] = {30, 20, 40, 70, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        bst.insert(arr[i]);

    cout << "Elements in BST(Iterative):\n";
    bst.inorder(bst.root);
    cout << "\n";

    cout << "Count of Elements: " << bst.countNodes(bst.root);
    cout << "\nMedian: " << bst.median(bst.root) << "\n";

    return 0;
}