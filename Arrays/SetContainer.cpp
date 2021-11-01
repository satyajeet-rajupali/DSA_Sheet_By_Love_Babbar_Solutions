#include <iostream>
#include <set>
#include <iterator>

using namespace std;

void showSet(set<int> st)
{

    cout << "Elements in set:\n";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    set<int> myset{101, 102, 103, 104, 105, 106};

    showSet(myset);

    cout << "Size of myset: " << myset.size() << endl;
    cout << "Max Size of myset: " << myset.max_size() << endl;

    if (myset.empty())
    {
        cout << "set is empty\n";
    }
    else
    {
        cout << "Set isn't empty\n";
    }

    set<int> st1;

    for (int i = 1; i <= 10; i++)
    {
        st1.insert(i);
    }

    showSet(st1);

    st1.insert(myset.find(102), myset.end());

    showSet(st1);

    set<int>::iterator it1, it2;

    it2 = st1.end();
    it2--;
    it2--;
    st1.erase(it2);
    showSet(st1);

    it1 = st1.begin();
    it2 = st1.end();
    advance(it1, 10);
    st1.erase(it1, it2);

    showSet(st1);

    myset.clear();
    showSet(myset);

    set<int>::key_compare comp = st1.key_comp();
    it1 = st1.begin();
    int l = *(st1.rbegin());
    cout << "Elements using key_comp():\n";
    do
    {
        cout << *it1 << " ";
    } while (comp(*(it1++), l));
    cout << endl;

    set<int>::value_compare vcomp = st1.value_comp();
    it1 = st1.begin();
    l = *(st1.rbegin());
    cout << "Elements using value_comp():\n";
    do
    {
        cout << *it1 << " ";
    } while (vcomp(*(it1++), l));
    cout << endl;

    if (st1.count(11))
        cout << "11 is present in the set\n";
    else
        cout << "11 is not present in the set\n";

    set<int>::iterator it3 = st1.lower_bound(9);

    cout << "Lower Bound of 9: " << *it3 << endl;

    it3 = st1.upper_bound(4);
    cout << "Lower Bound of 4: " << *it3 << endl;

    it3 = st1.upper_bound(6);
    cout << "Lower Bound of 6: " << *it3 << endl;

    auto it4 = st1.equal_range(6);
    cout<<"The lower bound of 6 is: "<<*it4.first<<"\n";
    cout<<"The upper bound of 6 is: "<<*it4.second<<"\n";


    set<int> st2;
    st2.insert(56);
    st2.insert(10);
    st2.insert(1);
    st2.emplace(100);
    showSet(st2);



    return 0;
}