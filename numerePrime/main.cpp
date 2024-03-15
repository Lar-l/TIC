#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream imputFile( "BAC.TXT" );
    int numberLenght , temporaryNumber,readNumbers=0;
    imputFile >> numberLenght;
    int numbers[numberLenght];
    while(readNumbers < numberLenght){
        imputFile >> temporaryNumber;
        cout << temporaryNumber << endl;
        readNumbers++;
    }
    /*
    for(int i = 10; i < 10 + numberLenght; i++) {
        //imputFile >> temporaryNumber;
        imputFile >> numbers[i-10];
        cout << "Numarul citit este:" << numbers[i-10] << endl;
    }
    for(int i = 0; i < numberLenght; i++)

    {
        cout << "numbers["<<i<<"]=" << numbers[i] << endl;
    }
    */

    return 0;
}
