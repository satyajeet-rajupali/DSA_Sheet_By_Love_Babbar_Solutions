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

bool check(Node *root)
{
    // Your code here

    queue<Node *> q;
    // unordered_map<int, int> m;
    set<int> s;
    int countLevel = 0;
    q.emplace(root);
    Node *p;

    bool istrue = true;

    while (!q.empty())
    {

        int n = q.size();

        while (n--)
        {
            /* code */
            p = q.front();
            q.pop();

            if (p->left)
                q.emplace(root->left);

            if (p->right)
                q.emplace(root->right);

            if (!p->left and !p->right)
            {
                // if (m.count(countLevel) == 0)
                //     m[countLevel] = 1;
                // else
                //     m[countLevel]++;
                s.emplace(countLevel);
            }
        }
        if (s.size() > 1)
        {
            istrue = false;
            break;
        }
        countLevel++;
    }

    return istrue;
}

bool checkUtil(Node *root, int level, int &leafLevel)
{
    if (!root)
        return true;

    if (!root->left and !root->right)
    {

        if (leafLevel == 0)
        {
            leafLevel = level;
            return true;
        }
        return (leafLevel == level);
    }

    return (checkUtil(root->left, level + 1, leafLevel) and checkUtil(root->right, level + 1, leafLevel));
}

bool check1(Node *root)
{

    int leafLevel = 0;
    return checkUtil(root, 0, leafLevel);
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);

    if (check(root))
        cout << "All leaf node at same level\n";
    else
        cout << "Not all leaf node at same level\n";

    return 0;
}