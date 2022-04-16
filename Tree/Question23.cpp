#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    char data;
};

// const char MARKER = '$';

Node *createTree()
{
    Node *root = new Node;
    char x;
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

        if (x != 'n')
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

        cout << "Enter right node of " << p->data << " :\n";
        cin >> x;

        if (x != 'n')
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

void dupSubUtil(Node *root, unordered_map<char, string> &um, int &label)
{
    if (!root)
    {
        return;
    }

    if (um.count(root->data) == 0)
    {
        if (root->left and root->right)
            um[root->data] = to_string(root->left->data) + to_string(root->right->data);
        else if (!root->left and root->right)
            um[root->data] = 'N' + to_string(root->right->data);
        else if (root->left and !root->right)
            um[root->data] = to_string(root->left->data) + 'N';
    }
    else
    {
        if (root->left and root->right)
        {
            if ((to_string(root->left->data) + to_string(root->right->data)).compare(um[root->data]) == 0)
                label = 1;
        }
        else if (!root->left and root->right)
        {
            if (('N' + to_string(root->right->data)).compare(um[root->data]) == 0)
                label = 1;
        }
        else if (root->left and !root->right)
        {
            if ((to_string(root->left->data) + 'N').compare(um[root->data]) == 0)
                label = 1;
        }
    }

    dupSubUtil(root->left, um, label);
    dupSubUtil(root->right, um, label);
}

string dupSubUtil(Node *root, unordered_set<string> &us, char &MARKER)
{

    string s = "";

    if (!root)
        return s + MARKER;

    string lstr = dupSubUtil(root->left, us, MARKER);
    if (lstr.compare(s) == 0)
        return s;

    string rstr = dupSubUtil(root->right, us, MARKER);
    if (rstr.compare(s) == 0)
        return s;

    s = s + root->data + lstr + rstr;

    if (s.length() > 3 and us.find(s) != us.end())
        return "";

    us.insert(s);

    return s;
}

int dupSub(Node *root)
{
    // code here
    unordered_set<string> us;
    char m = '$';
    string ans = dupSubUtil(root, us, m);
    return ans.compare("") == 0 ? 1 : 0;
}

int main()
{
    Node *root = createTree();

    cout << "Elements in the tree:\n";
    preorder(root);
    cout << "\n";

    if (dupSub(root))
        cout << "Tree Contains Duplicate\n";
    else
        cout << "Tree doesn't contain duplicate\n";

    return 0;
}