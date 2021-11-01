#include <iostream>
#include <map>

using namespace std;

void showMap(map<string, int> mp)
{
    cout << "Elements in map:\n";
    cout << "\tKEY\tVALUE\n";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << "\t" << it->first << "\t" << it->second << "\n";
    }
}

int main()
{

    map<string, int> mp;

    // Inserting a single value
    mp.insert(pair<string, int>("A", 1));
    mp.insert(pair<string, int>("B", 2));
    mp.insert(pair<string, int>("C", 3));
    mp.insert(pair<string, int>("D", 4));
    mp.insert(pair<string, int>("E", 5));

    showMap(mp);

    mp.insert(mp.find("C"), pair<string, int>("Poetry", 10));

    showMap(mp);

    map<string, int> mp1;
    mp1.insert(pair<string, int>("Maths", 10));
    mp1.insert(pair<string, int>("Grammar", 7));
    mp1.insert(pair<string, int>("Social", 8));
    mp1.insert(pair<string, int>("Hindi", 10));
    mp1.insert(pair<string, int>("GK", 10));

    showMap(mp1);

    cout << "After insertin a range of elements\n";
    mp.insert(mp1.begin(), mp1.end());

    showMap(mp);
    showMap(mp1);

    // Using erase() function
    // Removing elements using key
    mp.erase("GK");
    showMap(mp);

    // Removing elements using iterator position
    auto it = mp.find("Grammar");
    mp.erase(it);
    showMap(mp);

    // Removing a range of elements from the map
    auto it1 = mp.find("Hindi");
    mp.erase(it1, mp.end());
    showMap(mp);

    if (mp.count("A"))
    {
        cout << "A is present in the mp1\n";
    }
    else
    {
        cout << "A is not present in the mp1";
    }

    pair<map<string, int>::iterator, map<string, int>::iterator> it2;
    it2 = mp.equal_range("C");
    cout<<"Elements in the range\n";
    cout<<"The lower bound is "<<it2.first->first<<" : "<<it2.first->second<<endl;
    cout<<"The upper bound is "<<it2.second->first<<" : "<<it2.second->second<<endl;

    mp.insert(pair<string, int>("GK", 20));
    mp.emplace(pair<string, int>("MK", 20));
    showMap(mp);

    map<string, int> mp2;
    

    cout<<"Max Size of Map Container: "<<mp.max_size()<<endl;
    cout<<"Max Size of Map Container: "<<mp2.max_size()<<endl;



    return 0;
}