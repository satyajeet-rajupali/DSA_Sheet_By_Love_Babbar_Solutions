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

void preorder(Node *t)
{
    if (t)
    {
        cout << t->value << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

void diagonalTravresalUtil(Node *root, map<int, vector<int>> &mv, int d)
{

    if (!root)
        return;

    mv[d].push_back(root->value);
    diagonalTravresalUtil(root->left, mv, d + 1);
    diagonalTravresalUtil(root->right, mv, d);
}

void iterativeDiagonalTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> lq;
    Node *p = root;

    while (p)
    {
        cout << p->value << " ";

        if (p->left)
            lq.emplace(p->left);

        if (p->right)
            p = p->right;
        else
        {
            if (!lq.empty())
            {
                p = lq.front();
                lq.pop();
            }
            else
            {
                p = nullptr;
            }
        }
    }
}

void diagonalTraversal(Node *root)
{
    queue<Node *> q;
    q.emplace(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            while (temp)
            {
                cout << temp->value << " ";

                if (temp->left)
                    q.emplace(temp->left);

                temp = temp->right;
            }
        }
    }
}

int main()
{
    Node *root = createTree();

    cout << "Diagonal Traversal:\n";
    // map<int, vector<int>> mv;
    // diagonalTravresalUtil(root, mv, 0);
    // for (auto it : mv)
    // {
    //     for (auto i : it.second)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }

    // iterativeDiagonalTraversal(root);
    diagonalTraversal(root);

    return 0;
}