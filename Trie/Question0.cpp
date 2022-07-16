#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool terminal = false;

    Node()
    {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        terminal = true;
    }

    bool isEnd()
    {
        return terminal;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie();
    void insert(string word);
    bool search(string word);
};

Trie::Trie()
{
    root = new Node;
}

void Trie::insert(string word)
{
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
    }

    node->setEnd();
}

bool Trie::search(string word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            return false;
        }
        node = node->get(word[i]);
    }

    return node->isEnd();
}

int main()
{
    Trie tr;
    tr.insert("hello");
    tr.insert("why");
    tr.insert("drama");

    cout << tr.search("hello") << "\n";
    cout << tr.search("why") << "\n";
    cout << tr.search("drama") << "\n";

    return 0;
}