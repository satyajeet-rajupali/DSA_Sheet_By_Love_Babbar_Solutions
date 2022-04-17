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

string printAllDupsUtil(Node *root, vector<Node *> &dups, unordered_map<string, int> &mp)
{
    if (!root)
        return "";

    // cout << "Size of set: " << set.size() << "\n";
    // cout << "Size of dups: " << dups.size() << "\n";

    string left = printAllDupsUtil(root->left, dups, mp);
    string right = printAllDupsUtil(root->right, dups, mp);

    string ans = to_string(root->data) + "$" + left + "$" + right;
    if (mp[ans] == 1)
        dups.push_back(root);
    mp[ans]++;
    return ans;
}

void display(vector<Node *> dups)
{
    cout << "Size of Dups: " << dups.size() << "\n";
    cout << "Duplicate Elements:\n";
    for (int i = 0; i < dups.size(); i++)
        preorder(dups[i]);
    cout << "\n";
}

vector<Node *> printAllDups(Node *root)
{
    // Code here
    vector<Node *> dups;
    unordered_map<string, int> map;
    dups.clear();
    map.clear();
    printAllDupsUtil(root, dups, map);
    return dups;
}

int main()
{
    Node *root = createTree();

    // cout << "Elements in the tree:\n";
    // preorder(root);
    display(printAllDups(root));

    return 0;
}