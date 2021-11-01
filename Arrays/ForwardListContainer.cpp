#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

void showForwardList(forward_list<int> g)
{
    forward_list<int>::iterator it;
    cout << "Elements in the list:\n";
    for (it = g.begin(); it != g.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    forward_list<int> fl1, fl2, fl3;
    list<int> l;
    l.assign({243, 53, 59, 11});

    fl1.assign({1, 2, 3, 4, 5, 6});
    showForwardList(fl1);

    fl2.assign(5, 10);
    showForwardList(fl2);

    fl3.assign(fl1.begin(), fl1.end());
    showForwardList(fl3);

    fl3.assign(fl2.begin(), fl2.end());
    showForwardList(fl3);

    fl1.push_front(0);
    showForwardList(fl1);

    fl3.emplace_front(108);
    showForwardList(fl3);

    fl2.pop_front();
    fl2.pop_front();
    showForwardList(fl2);

    // Insert operations using insert_after()
    forward_list<int>::iterator it;
    it = fl3.begin();
    //advance(it,1);
    // Inserting single element after defined position into the list.
    fl3.insert_after(it, 91);
    showForwardList(fl3);

    it = fl2.begin();
    advance(it, 2);
    // Inserting multiple elements(or same elements) after defined position into the list.
    fl2.insert_after(it, 4, 20);
    showForwardList(fl2);

    it = fl1.begin();
    advance(it, 3);
    // Inserting a range of elements after defined position from one list to the other.
    fl1.insert_after(it, fl3.begin(), fl3.end());
    showForwardList(fl1);

    cout << "Printing list3:\n";
    // Inserting a list of elements after defined position
    fl3.insert_after(fl3.begin(), {1, 2, 3});
    showForwardList(fl3);

    fl2.clear();
    showForwardList(fl2);

    fl2.assign(2, 3);
    fl2.emplace_after(fl2.begin(), 10);
    showForwardList(fl2);

    showForwardList(fl1);

    return 0;
}