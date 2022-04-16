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

void sumOfLongRootToLeafPath(Node *root, int sum, int len, int &maxLen, int &maxSum)
{
    if (!root)
    {
        if (len > maxLen)
        {
            maxSum = sum;
            maxLen = len;
        }
        else if (len == maxLen and sum > maxSum)
            maxSum = sum;
        return;
    }

    sumOfLongRootToLeafPath(root->left, sum + root->data, len + 1, maxLen, maxSum);
    sumOfLongRootToLeafPath(root->right, sum + root->data, len + 1, maxLen, maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    // code here
    int maxLen = 0;
    int maxSum = INT_MIN;
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
    return maxSum;
}

int main()
{
    Node *root = createTree();
    cout << "Sum of longest path from root to leaf: " << sumOfLongRootToLeafPath(root) << "\n ";

    return 0;
}