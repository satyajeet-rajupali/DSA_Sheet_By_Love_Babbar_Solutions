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

// Node *lcaUtil(Node *root, int n1, int n2)
// {
//     if (!root or root->data == n1 or root->data == n2)
//         return root;

//     Node *left = lcaUtil(root->left, n1, n2);
//     Node *right = lcaUtil(root->right, n1, n2);

//     if (!left)
//     {
//         if (right)
//             cout << "Right Value returned: " << right->data << "\n";
//         else
//             cout << "Right NULL Returned\n";
//         return right;
//     }
//     else if (!right)
//     {
//         if (left)
//             cout << "Left Value returned: " << left->data << "\n";
//         else
//             cout << "Left NULL Returned\n";
//         return left;
//     }
//     else
//     {
//         if (root)
//             cout << "Root Value returned: " << root->data << "\n";
//         else
//             cout << "Root NULL Returned\n";
//         return root;
//     }
// }

// Node *lca(Node *root, int n1, int n2)
// {
//     Node *ans = new Node;
//     ans->data = -1;

//     Node *temp = lcaUtil(root, n1, n2);
//     if (!temp)
//         return ans;

//     return temp;
// }

Node *lcaUtil(Node *root, int n1, int n2)
{
    if (!root or root->data == n1 or root->data == n2)
    {
        return root;
    }

    Node *left = lcaUtil(root->left, n1, n2);
    Node *right = lcaUtil(root->right, n1, n2);

    if (!left)
        return right;
    else if (!right)
        return left;
    else
        return root;
}

Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    Node *ans = new Node;
    ans->data = -1;

    Node *temp = lcaUtil(root, n1, n2);
    if (!temp)
        return ans;

    return temp;
}

int main()
{
    Node *root = createTree();
    int n1 = 4, n2 = 6;
    Node *ans = lca(root, n1, n2);
    cout << "Lowest Common Ancestor: " << ans->data << "\n";

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}