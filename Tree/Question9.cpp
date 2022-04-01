#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int value;
};

Node *createTree()
{
    Node *root = new Node;
    int x;
    cout << "Enter root node:\n";
    cin >> x;
    root->value = x;
    root->left = nullptr;
    root->right = nullptr;

    queue<Node *> q;
    q.emplace(root);
    Node *t, *p;

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left node of " << p->value << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->value = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->value << " :\n";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->value = x;
            t->left = t->right = nullptr;
            p->right = t;
            q.emplace(t);
        }
    }

    return root;
}

// same as left view with the only difference of right node will be called firstly and then left node;
void right_view_util(Node *root, int level, int &maxLevel)
{

    if (!root)
        return;

    if (maxLevel < level)
    {
        cout << root->value << " ";
        maxLevel = level;
    }

    right_view_util(root->right, level + 1, maxLevel);
    right_view_util(root->left, level + 1, maxLevel);
}

void right_view(Node *root)
{
    int max_level = 0;
    right_view_util(root, 1, max_level);
    return;
}

void right_view_using_levelordertraversal(Node *root)
{
    queue<Node *> q;
    Node *p;

    q.emplace(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            p = q.front();
            q.pop();

            if (n == 0)
                cout << p->value << " ";

            if (p->left)
                q.emplace(p->left);

            if (p->right)
                q.emplace(p->right);
        }
    }
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root)
    cout << "Right View Using Recursion:\n";
    // right_view(root);
    // cout << "\n";

    // cout << "Right View Using Level Order Traversal:\n";
    // right_view_using_levelordertraversal(root);
    // cout << "\n";

    return 0;
}