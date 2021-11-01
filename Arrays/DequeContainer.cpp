#include <iostream>
#include <deque>

using namespace std;

void showDeque(deque<int> g)
{
    deque<int>::iterator it;
    cout << "Elements in the list:\n";
    for (it = g.begin(); it != g.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}



int main()
{
    deque<int> df,db;

    for(int i=1; i<=15; i++){
        df.push_front(i*5);
        db.push_back(i*7);
    }

    deque<int> d1, d2;
    d1 = df;
    d2 = db;

    showDeque(df);
    showDeque(db);

    for(int i=0; i<4; i++){
        df.pop_back();
        df.pop_front();
        db.pop_back();
        db.pop_front();
    }

    showDeque(df);
    showDeque(db);

    cout<<"Element at front in the df: "<<df.front()<<endl;
    cout<<"Element at back in the df: "<<df.back()<<endl;

    cout<<"Element at front in the db: "<<db.front()<<endl;
    cout<<"Element at back in the db: "<<db.back()<<endl;

    // df.clear();
    // db.clear();

    deque<int>::iterator dit1, dit2;

    df.erase(df.begin() + 2);
    db.erase(db.begin() + 2);

    dit1 = df.end() - 1;
    dit2 = db.end() - 1;

    showDeque(df);
    showDeque(db);

    df.erase(df.begin() + 1, dit1);
    db.erase(db.begin() + 1, dit2);

    showDeque(df);
    showDeque(db);

    if (df.empty())
    {
        cout << "df is Empty\n";
    }
    else
    {
        cout << "df isn't Empty\n";
    }

    if (db.empty())
    {
        cout << "db is Empty\n";
    }
    else
    {
        cout << "db isn't Empty\n";
    }

    cout<<"Size of df: "<<df.size()<<"\n";
    cout<<"Size of db: "<<db.size()<<"\n";

    cout<<"Element at 4 in d1: "<<d1[3]<<endl;
    cout<<"Element at 4 in d2: "<<d2[3]<<endl;

    cout<<"Element at 5 in d1: "<<d1.at(4)<<endl;
    cout<<"Element at 5 in d2: "<<d2.at(4)<<endl;


    cout<<"Before Swapping:\n";
    showDeque(d1);
    showDeque(d2);

    cout<<"After swapping:\n";
    d1.swap(d2);
    d1.swap(d2);
    d1.emplace_front(80);
    d2.emplace_back(112);

    showDeque(d1);
    showDeque(d2);

    df.insert(df.begin()+1, 50);
    db.insert(db.begin()+1, 42);

    showDeque(df);
    showDeque(db);

    deque<int>::iterator dit3,dit4, dit5, dit6;

    dit3 = d1.begin() + 7;
    dit4 = d1.end() - 5;

    dit5 = d2.begin() + 7;
    dit6 = d2.end() - 5;

    df.insert(df.begin(), dit3, dit4);
    db.insert(db.begin(), dit5, dit6);

    showDeque(df);
    showDeque(db);

    deque<int> d3, d4;
    d3.assign(5,100);
    d4.assign(5,200);

    showDeque(d3);
    showDeque(d4);











    return 0;
}