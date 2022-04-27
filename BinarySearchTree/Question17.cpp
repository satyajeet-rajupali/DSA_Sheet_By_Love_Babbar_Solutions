#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int low, high;
};

struct ITNode
{
    Interval *i;
    int max;
    ITNode *left, *right;
};

ITNode *newNode(Interval inode)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(inode);
    temp->max = inode.high;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

bool doOverlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high and i2.low < i1.high)
        return true;
    return false;
}

ITNode *insert(ITNode *root, Interval i)
{
    ITNode *t;
    if (!root)
    {
        t = newNode(i);
        return t;
    }

    int low = root->i->low;

    if (i.low < low)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    if (root->max < i.high)
        root->max = i.high;

    return root;
}

Interval *overlapSearch(ITNode *root, Interval i)
{
    if (!root)
        return nullptr;

    if (doOverlap(*(root->i), i))
        return root->i;

    if (root->left and root->left->max >= i.low)
        return overlapSearch(root->left, i);

    return overlapSearch(root->right, i);
}

void printOverLappingIntervals(Interval appointments[], int n)
{
    ITNode *root = nullptr;
    root = insert(root, appointments[0]);

    for (int i = 1; i < n; i++)
    {
        Interval *res = overlapSearch(root, appointments[i]);
        if (res)
        {
            cout << "[" << appointments[i].low << "," << appointments[i].high << "] conflicts with "
                 << "[" << res->low << "," << res->high << "]\n";
        }

        root = insert(root, appointments[i]);
    }
}

int main()
{

    Interval arr[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printOverLappingIntervals(arr, n);

    return 0;
}