#include <iostream>
#include <unordered_set>

using namespace std;

void showUnorderedSet(unordered_set<int> ust)
{
    cout << "Elements in Unordered Set:\n";
    for (auto it = ust.begin(); it != ust.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;
}

int main()
{
    unordered_set<int> uset1;

    for(int i=100; i<=110; i++){
        uset1.insert(i);
    }

    cout<<"Number of times 108 is present in the uset1: "<<uset1.count(108)<<endl;

    showUnorderedSet(uset1);

    unordered_set<int> uset2;

    for(int i=1; i<=10; i++){
        uset2.insert(i);
    }

    showUnorderedSet(uset2);

    uset1.insert(uset2.begin(), uset2.end());

    showUnorderedSet(uset1);

    // int bucketCount = uset1.bucket_count();
    // cout<<"Bucket Count of uset1: "<<bucketCount<<endl;

    // for(int i=0; i<bucketCount; i++){
    //     cout<<"Bucket size of the count "<<i<<" is: "<<uset1.bucket_size(i)<<endl;
    // }

    // Use of erase() function in the code
    uset1.erase(108);
    showUnorderedSet(uset1);

    uset1.erase(uset1.find(100));
    showUnorderedSet(uset1);


    unordered_set<int>::iterator it;
    it = uset1.begin();
    advance(it, 10);

    uset1.erase(it,uset1.end());

    showUnorderedSet(uset1);

    uset1.emplace(1091);
    showUnorderedSet(uset1);

    cout<<"Size of uset1: "<<uset1.size()<<endl;
    cout<<"Maximum size of uset1: "<<uset1.max_size()<<endl;

    // Hash Function
    unordered_set<int>::hasher fn = uset1.hash_function();
    cout<<"Hash value of 1091: "<<fn(1091)<<endl;





    return 0;
}