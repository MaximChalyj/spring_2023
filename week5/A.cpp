#include <iostream>
using namespace std;

int main()
{
    double* ptr;
    double value = 0;
    ptr = &value;
    *ptr = 0;
    cout << ptr << " " << *ptr << endl;
    *ptr -= 3; 
    cout << ptr << " " << *ptr << endl;
    *ptr += 5;
    cout << ptr << " " << *ptr << endl;
} 