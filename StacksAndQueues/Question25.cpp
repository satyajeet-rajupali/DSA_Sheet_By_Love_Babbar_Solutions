#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
};

class LRUCache
{

public:
    Node *cache, *tracker, *tail;
    unordered_map<int, Node *> m;
    int cap, counter = 0;

    Node *newNode(int key, int value);
    LRUCache(int cap);

    void set(int key, int value);
    int get(int key);

    void display(Node *node);
};

LRUCache::LRUCache(int cap)
{
    this->cap = cap;
    cache = NULL;
    Node *last = NULL;
    for (int i = 0; i < this->cap; i++)
    {
        if (!cache)
        {
            cache = newNode(-1, -1);
            last = cache;
        }
        else
        {
            Node *temp = newNode(-1, -1);
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
    tracker = cache;
    tail = last;
}

Node *LRUCache::newNode(int key, int value)
{
    Node *temp = new Node;
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void LRUCache::set(int key, int value)
{
    if (cap == 1)
    {
        cache->key = key;
        cache->value = value;
    }
    else
    {

        if (counter == cap)
        {
            if (m.find(key) == m.end())
            {
                Node *temp = cache;
                cache = cache->next;
                cache->prev = NULL;
                temp->next = NULL;
                m.erase(temp->key);
                temp->key = key;
                temp->value = value;
                tail->next = temp;
                temp->prev = tail;
                tail = tail->next;
                m[key] = tail;
            }
            else
            {
                Node *temp = m[key];
                temp->value = value;

                // Head Node
                if (temp == cache)
                {

                    cache = cache->next;
                    cache->prev = NULL;
                    temp->next = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = tail->next;
                } // Tail Node
                else if (temp == tail)
                {

                    tail->value = value;
                } // Middle Node
                else
                {

                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    temp->prev = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = tail->next;
                }

                m[key] = tail;
            }
        }
        else
        {

            if (m.find(key) == m.end())
            {
                tracker->key = key;
                tracker->value = value;
                m[key] = tracker;
                tail = tracker;
                tracker = tracker->next;
                counter++;
            }
            else
            {
                Node *temp = m[key];
                temp->value = value;

                // Head Node
                if (temp == cache)
                {

                    cache = cache->next;
                    cache->prev = NULL;
                    temp->next = NULL;
                    tracker->next = temp;
                    temp->prev = tracker;
                    tail = tracker;
                    tracker = tracker->next;
                } // Tail Node
                else if (temp == tracker)
                {

                    tracker->value = value;
                } // Middle Node
                else
                {

                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    temp->prev = NULL;
                    tracker->next = temp;
                    temp->prev = tracker;
                    tail = tracker;
                    tracker = tracker->next;
                }

                m[key] = tracker;
            }
        }
    }
}

void LRUCache::display(Node *node)
{

    cout << "Elemements in the cache\n";
    while (node)
    {
        cout << "(" << node->key << "," << node->value << ")<==>";
        node = node->next;
    }
    cout << "\n";
}

int LRUCache::get(int key)
{

    int val = -1;

    if (cap == 1)
    {
        if (cache->key == key)
        {
            val = cache->value;
        }
    }
    else
    {

        if (counter == cap)
        {
            if (m.find(key) != m.end())
            {
                Node *temp = m[key];
                val = temp->value;
                // Head Node
                if (temp == cache)
                {
                    cache = cache->next;
                    cache->prev = NULL;
                    temp->next = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = tail->next;
                }
                else if (temp == tail)
                {
                    // do nothing
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    temp->prev = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    tail = tail->next;
                }
            }
        }
        else
        {
            if (m.find(key) != m.end())
            {
                Node *temp = m[key];
                val = temp->value;
                // Head Node
                if (temp == cache)
                {
                    cache = cache->next;
                    cache->prev = NULL;
                    temp->next = NULL;
                    tail = tracker;
                    tracker->next = temp;
                    temp->prev = tracker;
                    tracker = tracker->next;
                }
                else if (temp == tracker)
                {
                    // do nothing
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    temp->prev = NULL;
                    tail = tracker;
                    tracker->next = temp;
                    temp->prev = tracker;
                    tracker = tracker->next;
                }
            }
        }
    }

    return val;
}

int main()
{
    LRUCache lru = LRUCache(8);
    // lru.set(1, 11);
    // lru.display(lru.cache);

    // cout << "Fectched Value:" << lru.get(1) << "\n";
    // lru.display(lru.cache);

    // lru.set(2, 22);

    // lru.set(2, 22);
    // lru.set(3, 33);
    // lru.set(4, 44);

    // lru.display(lru.cache);
    // lru.set(1, 100);
    // lru.display(lru.cache);

    // lru.set(1, 99);
    // lru.display(lru.cache);

    // lru.set(2, 108);
    // lru.display(lru.cache);
    // lru.set(3, 33);
    // lru.display(lru.cache);

    // lru.set(4, 44);
    // lru.set(5, 55);
    // lru.display(lru.cache);

    // lru.set(4, 99);
    // lru.display(lru.cache);

    // lru.set(3, 100);
    // lru.display(lru.cache);

    // cout << "Fectched Value:" << lru.get(2) << "\n";
    // lru.display(lru.cache);

    cout << "Fectched Value:" << lru.get(4) << "\n";
    // lru.display(lru.cache);

    // cout << "Fectched Value:" << lru.get(1) << "\n";
    // lru.display(lru.cache);

    return 0;
}