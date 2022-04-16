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

        if (x != -11)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->data << " :\n";
        cin >> x;

        if (x != -11)
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

void printPath(vector<int> path, int i)
{
    for (int j = i; j < path.size(); j++)
        cout << path[j] << " ";
    cout << "\n";
}

void printKPathUtil(Node *root, vector<int> &path, int k)
{

    if (!root)
        return;

    path.push_back(root->data);

    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);

    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];
        if (f == k)
            printPath(path, j);
    }

    path.pop_back();
}

// Paths from root only
void printPathsUtil(Node *root, int sum_so_far, int sum, vector<int> &path)
{

    if (!root)
        return;

    path.push_back(root->data);

    sum_so_far += root->data;

    if (sum == sum_so_far)
    {
        cout << "Path Found: ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << "\n";
    }

    if (root->left)
        printPathsUtil(root->left, sum_so_far, sum, path);

    if (root->right)
        printPathsUtil(root->right, sum_so_far, sum, path);

    path.pop_back();
}

void printKPath(Node *root, int k)
{
    vector<int> paths;
    printPathsUtil(root, 0, k, paths);
}

int main()
{
    Node *root = createTree();
    int k = 5;
    printKPath(root, k);

    // cout << "Elements in the tree:\n";
    // preorder(root);

    return 0;
}