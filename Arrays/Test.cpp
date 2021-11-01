#include <iostream>
#include <vector>
  
using namespace std;
  
int main()
{
    vector<int> g1;
    vector<int> g2;

    g2.assign({1000,2000,3000,4000,5000});

  
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
  
    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
  
    
    // Inserting element at specified position
    g1.insert(g1.begin()+4,100);

    // Inserting multiple elements at specified position
    g1.insert(g1.begin()+4, 4, 7);

    // Inserting elements from one vector to another
    g1.insert(g1.begin()+3, g2.begin(), g2.end());



    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

  
    return 0;
}