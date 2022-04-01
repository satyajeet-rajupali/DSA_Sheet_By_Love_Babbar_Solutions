#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
};

Node *createTree()
{
    Node *root = new Node;
    int x;
    cout << "Enter root node:\n";
    cin >> x;
    root->data = x;
    root->left = nullptr;
    root->right = nullptr;

    queue<Node *> q;
    q.emplace(root);
    Node *t, *p;

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left node of " << p->data << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->data << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            q.emplace(t);
        }
    }

    return root;
}

void preorder(Node *t)
{
    if (t)
    {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

void printLeaves(Node *root, vector<int> &ans)
{

    if (!root)
        return;

    printLeaves(root->left, ans);
    if (!root->left and !root->right)
        ans.push_back(root->data);
    printLeaves(root->right, ans);
}

void printLeftLeaves(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        printLeftLeaves(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        printLeftLeaves(root->right, ans);
    }
}

void printRightLeaves(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->right)
    {
        printRightLeaves(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        printRightLeaves(root->left, ans);
        ans.push_back(root->data);
    }
}

// vector<int> boundary(Node *root)
// {
//     // Your code here
//     if (!root)
//         return;
//     cout << root->data << " ";
//     printLeftLeaves(root->left);
//     printLeaves(root->left);
//     printLeaves(root->right);
//     printRightLeaves(root->right)
// }

vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);
    printLeftLeaves(root->left, ans);
    printLeaves(root->left, ans);
    printLeaves(root->right, ans);
    printRightLeaves(root->right, ans);

    return ans;
}

int main()
{
    Node *root = createTree();

    vector<int> ans = boundary(root);
    cout << "Boundary Elements:\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    // cout << "Elements in the tree:\n";
    // preorder(root);
    // boundary(root);

    return 0;
}