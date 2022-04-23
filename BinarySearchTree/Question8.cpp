#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    int height;
    Node *right;
};

class AVLTree
{
public:
    Node *root;
    AVLTree() { root = nullptr; };
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *inorderSuccessor(Node *p);
    Node *inorderPredecessor(Node *p);

    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);

    void inorder(Node *p);
    Node *insert(Node *p, int key);
    Node *Delete(Node *p, int key);
};

int AVLTree::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p and p->left) ? p->left->height : 0;
    hr = (p and p->right) ? p->right->height : 0;

    return (hl > hr ? hl + 1 : hr + 1);
}

int AVLTree::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p and p->left) ? p->left->height : 0;
    hr = (p and p->right) ? p->right->height : 0;

    return hl - hr;
}

Node *AVLTree::inorderSuccessor(Node *p)
{
    while (p and p->left)
        p = p->left;
    return p;
}

Node *AVLTree::inorderPredecessor(Node *p)
{
    while (p and p->right)
        p = p->right;
    return p;
}

Node *AVLTree::LLRotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;
    return pl;
}

Node *AVLTree::RRRotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;
    return pr;
}

Node *AVLTree::LRRotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}

Node *AVLTree::RLRotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

void AVLTree::inorder(Node *p)
{
    if (!p)
        return;
    inorder(p->left);
    cout << p->data << " ";
    inorder(p->right);
}

Node *AVLTree::insert(Node *p, int key)
{

    Node *t;

    if (!p)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->left = nullptr;
        t->right = nullptr;
        return t;
    }

    if (key < p->data)
        p->left = insert(p->left, key);
    else if (key > p->data)
        p->right = insert(p->right, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 and BalanceFactor(p->left) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 and BalanceFactor(p->left) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 and BalanceFactor(p->right) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 and BalanceFactor(p->right) == 1)
        return RLRotation(p);

    return p;
}

Node *AVLTree::Delete(Node *p, int key)
{
    if (!p)
        return p;

    if (!p->left and !p->right)
    {
        if (root == p)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->data)
        p->left = Delete(p->left, key);
    else if (key > p->data)
        p->right = Delete(p->right, key);
    else
    {
        Node *q;
        if (NodeHeight(p->left) > NodeHeight(p->right))
        {
            q = inorderPredecessor(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = inorderSuccessor(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 and BalanceFactor(p->left) == 0) // L0
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 and BalanceFactor(p->left) == 1) // L1
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 and BalanceFactor(p->left) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 and BalanceFactor(p->right) == 0)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 and BalanceFactor(p->right) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 and BalanceFactor(p->right) == 1)
        return RLRotation(p);
    return p;
}

int main()
{

    int arr[] = {10, 20, 30, 25, 28, 27, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    AVLTree avt;
    for (int i = 0; i < n; i++)
        avt.root = avt.insert(avt.root, arr[i]);

    cout << "Elements in AVL Tree:\n";
    avt.inorder(avt.root);
    cout << "\n";

    avt.Delete(avt.root, 28);

    cout << "Elements in AVL Tree Post Deletion:\n";
    avt.inorder(avt.root);
    cout << "\n";

    return 0;
}