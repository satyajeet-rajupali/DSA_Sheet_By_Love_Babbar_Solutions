#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// The important thing to remember is that the implementation of STL list is based
// on Doubly Linked List of DSA

// Display function for list
void showList(list<int> g)
{
    list<int>::iterator it;
    cout << "Elements in the list:\n";
    for (it = g.begin(); it != g.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool even(const int &value) { return (value % 2) == 0; }

bool odd(const int &value) { return (value % 2) != 0; }

bool comparator(int first, int second) { return first > second; }

int main()
{

    // Declaration of list containers
    list<int> l1, l2;

    // Inserting elements in the list
    for (int i = 1; i < 11; i++)
    {
        l1.push_front(i * 5);
        l2.push_back(i * 3);
    }

    showList(l1);
    showList(l2);
    // for(int i=1; i<3; i++){
    //     l2.pop_front();
    //     l2.pop_back();
    // }

    // showList(l1);
    // showList(l2);

    // Printing the values present at the front and end of the list
    cout << "Value at front in l1: " << l1.front() << endl;
    cout << "Value at back in l1: " << l1.back() << endl;

    cout << "Value at front in l2: " << l2.front() << endl;
    cout << "Value at back in l2: " << l2.back() << endl;

    if (l1.empty())
    {
        cout << "L1 is Empty\n";
    }
    else
    {
        cout << "L1 isn't Empty\n";
    }

    if (l2.empty())
    {
        cout << "L2 is Empty\n";
    }
    else
    {
        cout << "L2 isn't Empty";
    }

    // Declaration of iterators
    list<int>::iterator pit, pit1;
    pit = l1.end();

    // Insertion of element in the list using insert funtion
    l1.insert(pit, 4, 100); // (Insertion of multiple elements in the list) InInserting 100, 4 times in the list
    l1.insert(pit, 200);    // (Insertion of single element in the list) Inserting 200 in the list

    pit = l1.begin();
    l1.insert(pit, 4, 100);
    l1.insert(pit, 200);

    pit = l2.end();
    l2.insert(pit, 4, 100);
    l2.insert(pit, 200);

    pit = l2.begin();
    l2.insert(pit, 4, 100);
    l2.insert(pit, 200);

    showList(l1);
    showList(l2);

    cout << "Value at front in l1: " << l1.front() << endl;
    cout << "Value at back in l1: " << l1.back() << endl;

    cout << "Value at front in l2: " << l2.front() << endl;
    cout << "Value at back in l2: " << l2.back() << endl;

    pit = l1.begin();
    pit1 = l2.begin();

    // Erase operation on list to erase elements from the list
    l1.erase(pit);
    l2.erase(pit1);

    // pit = l2.begin();
    // pit1 = l2.begin();
    // l2.erase(pit);
    // pit = l2.begin();
    // advance(pit1,4);
    // l2.erase(pit,pit1);
    // pit = l2.end();
    // l2.erase(pit);

    showList(l1);
    showList(l2);

    cout << "Value at front in l1: " << l1.front() << endl;
    cout << "Value at back in l1: " << l1.back() << endl;

    cout << "Value at front in l2: " << l2.front() << endl;
    cout << "Value at back in l2: " << l2.back() << endl;

    // assign() operation on the list to assign elements in the list
    l1.assign(10, 1111);
    l2.assign(10, 3333);

    showList(l1);
    showList(l2);

    l1.assign(l2.begin(), l2.end());

    showList(l1);
    showList(l2);

    // remove() operation on list to remove a given element from the list to remove from
    // all the positions where it is present
    l1.remove(3333);
    l2.remove(3333);

    showList(l1);
    showList(l2);

    l1.sort();
    l2.sort();

    showList(l1);
    showList(l2);

    // unique() opeartion on list to remove duplicate elements from the list(It works only on sorted list).
    l1.unique();
    l2.unique();

    l1.remove_if(odd);
    l2.remove_if(even);

    showList(l1);
    showList(l2);

    // reverse() operation to reverse the order in which the elements are present in the list.
    l1.reverse();
    l2.reverse();

    cout << "\n\nLists after being reversed:\n\n";
    showList(l1);
    showList(l2);

    cout << "Size of List l1: " << l1.size() << endl;
    cout << "Size of List l2: " << l2.size() << endl;

    l1.resize(7);
    l2.resize(7, 5);

    // sort() operation on the list is to sort the elements present in the list.
    l1.sort();
    l2.sort();

    showList(l1);
    showList(l2);

    cout << "MaxSize of List l1: " << l1.max_size() << endl;
    cout << "MaxSize of List l2: " << l2.max_size() << endl;

    // Trasnferring elements from one list to the other
    l1.splice(l1.begin(), l2);

    showList(l1);
    showList(l2);

    list<int>::iterator sit = l1.begin();

    // Trasnferring one element from one list to the other
    l2.splice(l2.begin(), l1, sit);

    showList(l1);
    showList(l2);

    list<int>::iterator ssit = l1.begin();

    advance(ssit, 3);

    l2.splice(l2.begin(), l1, ssit, l1.end());

    showList(l1);
    showList(l2);

    // Merging two lists

    cout << "\nAfter Merging:\n";
    l1.sort();
    l2.sort();
    //l1.merge(l2);
    l1.merge(l2, comparator); // Merging with comparators.
    showList(l1);
    showList(l2);

    list<int>::iterator xit = l1.begin();
    advance(xit, 4);

    list<int>::iterator zit = l1.emplace(xit, 91);
    showList(l1);
    showList(l2);

    cout << "Element is: " << *zit << endl;

    return 0;
}