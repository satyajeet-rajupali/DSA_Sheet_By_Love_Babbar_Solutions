#include<iostream>
#include<utility>

using namespace std;


int main(){

    pair<int, char> PAIR1;

    PAIR1.first = 100;
    PAIR1.second = 'C';

    cout<<"Elements in PAIR1:\n";
    cout<<"First Element: "<<PAIR1.first<<endl;
    cout<<"Second Element: "<<PAIR1.second<<endl;

    pair<string, double> PAIR2("GeeksForGeeks", 3.456);

    cout<<"Elements in PAIR2:\n";
    cout<<"First Element: "<<PAIR2.first<<endl;
    cout<<"Second Element: "<<PAIR2.second<<endl;

    pair<string, double> PAIR3 = make_pair("SAM TINNESZ", 4.56);

    cout<<"Elements in PAIR3:\n";
    cout<<"First Element: "<<PAIR3.first<<endl;
    cout<<"Second Element: "<<PAIR3.second<<endl;



    return 0;
}