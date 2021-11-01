#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int main()
{
    array<int, 6> ar = {1, 2, 3, 4, 5, 6};

    cout << "Elements in array(Using array-name.at(index)):\n";
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar.at(i) << " ";
    }
    cout << endl;

    cout << "Elements in array(Using get<index>(array-name)):\n";
    cout << get<0>(ar) << " " << get<1>(ar) << " " << get<2>(ar) << " " << get<3>(ar) << " " << get<4>(ar) << " " << get<5>(ar);
    cout << endl;

    cout << "Elements in array(Using operator array-name[index]):\n";
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;

    cout << "Element at the front of the array: " << ar.front() << endl;
    cout << "Element at the back of the array: " << ar.back() << endl;

    cout << "Size of the array: " << ar.size() << endl;
    cout << "Maximum_Size of the array: " << ar.max_size() << endl;

    array<int, 0> array1;
    if (array1.empty())
    {
        cout << "Array is empty\n";
    }
    else
    {
        cout << "Array isn't empty\n";
    }

    array<int, 6> array2;
    array2.fill(10000);

    cout << "Elements in array2(Using array-name.at(index)):\n";
    for (int i = 0; i < array2.size(); i++)
    {
        cout << array2.at(i) << " ";
    }
    cout << endl;

    ar.swap(array2);
    cout << "\n\nElements in the arrays after swapping\n\n";

    cout << "Elements in ar(Using array-name.at(index)):\n";
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar.at(i) << " ";
    }
    cout << endl;

    cout << "Elements in array2(Using array-name.at(index)):\n";
    for (int i = 0; i < array2.size(); i++)
    {
        cout << array2.at(i) << " ";
    }
    cout << endl;

    return 0;
}