#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = 1;
    cout << a << " ";
    cout << b << " ";
    for(int index = 1;index < 7; index++){
        int suma = a + b;
        cout << suma << " ";
        a = b;
        b = suma;
    }
    return 0;
}
