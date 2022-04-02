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

Node *stringToTree(string str)
{
    cout << "Working-1\n";
    stack<Node *> stk;

    Node *root = new Node;
    root->data = str[0] - '0';
    root->left = root->right = nullptr;

    Node *p = root;
    Node *temp;
    int i = 1;

    cout << "Working-2\n";

    while (i < str.length())
    {
        cout << "Working-3\n";

        if (str[i] == '(' and str[i - 1] != ')')
        {
            cout << "Working-4\n";
            if (str[i + 1] != '(' and str[i + 1] != ')')
            {
                temp = new Node;
                temp->data = str[i + 1] - '0';
                temp->left = temp->right = nullptr;
                p->left = temp;
                stk.emplace(p);
                p = p->left;
                temp = nullptr;
            }
        }
        else if (str[i] == ')' and str[i + 1] == '(')
        {
            p = stk.top();
            stk.pop();
            cout << "Working-5\n";
            if (str[i + 1] != '(' and str[i + 1] != ')')
            {
                temp = new Node;
                temp->data = str[i + 2] - '0';
                temp->left = temp->right = nullptr;
                p->right = temp;
                p = p->right;
                temp = nullptr;
            }
        }
        i++;
    }
    cout << "Working-6\n";
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

int main()
{
    // Node *root = createTree();
    string str = "1(2()(3(4)))";

    Node *root = stringToTree(str);
    cout << "Elements in the tree:\n";
    inorder(root);
    cout << "\n";

    return 0;
}