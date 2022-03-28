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

void postorder(Node *t)
{
    if (t)
    {
        postorder(t->left);
        postorder(t->right);
        cout << t->value << " ";
    }
}

void iterative_postorder(Node *root)
{
    stack<long int> stk;
    long int temp;
    while (root or !stk.empty())
    {
        if (root)
        {
            stk.emplace((long int)root);
            root = root->left;
        }
        else
        {
            temp = stk.top();
            stk.pop();

            if (temp > 0)
            {
                stk.emplace(-temp);
                root = ((Node *)temp)->right;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->value << " ";
                root = nullptr;
            }
        }
    }
}

int main()
{
    Node *root = createTree();

    cout << "Recursive Postorder Traversal:\n";
    postorder(root);
    cout << "\n";

    cout << "Iterative Postorder Traversal:\n";
    iterative_postorder(root);
    cout << "\n";

    return 0;
}