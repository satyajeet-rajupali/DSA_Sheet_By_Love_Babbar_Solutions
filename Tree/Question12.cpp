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

void randomTraversal(Node *root)
{

    priority_queue<pair<int, Node *>> pq;

    pq.emplace(make_pair(root->value, root));
    Node *p;

    while (!pq.empty())
    {
        p = pq.top().second;
        pq.pop();

        cout << p->value << " ";

        if (p->left)
            pq.emplace(make_pair(p->left->value, p->left));

        if (p->right)
            pq.emplace(make_pair(p->right->value, p->right));
    }
}

void zigZagTraversal(Node *root)
{
    if (!root)
        return;

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;
    currentLevel.emplace(root);
    Node *p;

    while (!currentLevel.empty())
    {
        p = currentLevel.top();
        currentLevel.pop();

        if (p)
        {
            cout << p->value << " ";

            if (leftToRight)
            {
                if (p->left)
                    nextLevel.emplace(p->left);
                if (p->right)
                    nextLevel.emplace(p->right);
            }
            else
            {
                if (p->right)
                    nextLevel.emplace(p->right);
                if (p->left)
                    nextLevel.emplace(p->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            currentLevel.swap(nextLevel);
        }
    }
}

int main()
{
    Node *root = createTree();
    zigZagTraversal(root);
    randomTraversal(root);

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}