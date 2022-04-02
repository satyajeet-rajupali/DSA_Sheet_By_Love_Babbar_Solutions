#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
};

void displayDLL(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << "\n";
}

Node *createTree()
{
    queue<Node *> q;
    Node *root = new Node;
    Node *p, *temp;
    int x;

    cout << "Enter root node:\n";
    cin >> x;
    root->data = x;
    root->left = root->right = nullptr;

    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << ":\n";
        cin >> x;
        if (x != -1)
        {
            temp = new Node;
            temp->data = x;
            temp->left = temp->right = nullptr;
            p->left = temp;
            q.emplace(temp);
        }

        cout << "Enter right child of " << p->data << " :\n";
        cin >> x;
        if (x != -1)
        {
            temp = new Node;
            temp->data = x;
            temp->left = temp->right = nullptr;
            p->right = temp;
            q.emplace(temp);
        }
    }

    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void bTdUtil(Node *root, Node *&head, Node *&prev, int &f)
{
    if (!root)
        return;

    bTdUtil(root->left, head, prev, f);

    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    bTdUtil(root->right, head, prev, f);
}

Node *bToDLL(Node *root)
{
    // your code here
    Node *head = nullptr;
    Node *prev = nullptr;
    int f = 0;
    bTdUtil(root, head, prev, f);
    return head;
}

int main()
{
    Node *root = createTree();
    cout << "Elements in Tree:\n";
    inorder(root);
    cout << "\n";
    cout << "Elements in DLL:\n";
    Node *head = bToDLL(root);
    displayDLL(head);

    return 0;
}