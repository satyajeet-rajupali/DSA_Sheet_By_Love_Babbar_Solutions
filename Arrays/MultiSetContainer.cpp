#include<iostream>
#include<set>

using namespace std;

void showMultiSet(multiset<int> st)
{

    cout << "Elements in set:\n";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    multiset<int> ms1;
    
    for(int i=0; i<=7; i++){
        ms1.insert(i);
    }

    ms1.insert(108);

    for(int i=5; i<=10; i++){
        ms1.insert(i);
    }


    showMultiSet(ms1);


    // Removes all instance of the provided elements
    ms1.erase(ms1.find(6));
    showMultiSet(ms1);

    ms1.erase(6);
    showMultiSet(ms1);

    cout<<"The Lower Bound of 5 is "<<*ms1.lower_bound(5)<<endl;
    cout<<"The Upper Bound of 5 is "<<*ms1.upper_bound(5)<<endl;



    return 0;
}