#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream numbersFile ( "numere.txt" );
    int maxNumber, minNumber, number;
    numbersFile >> maxNumber;
    minNumber = maxNumber;
    while( numbersFile >> number ){
        if( number > maxNumber ){
            maxNumber = number;
        }
        if( number < minNumber ){
            minNumber = number;
        }
    }
    cout << "Max number: " << maxNumber << endl;
    cout << "Min number: " << minNumber << endl;

    return 0;
}
