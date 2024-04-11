#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("numerele.in");
    ofstream fout("numerele.out");
    int maxNumber,minNumber,number;
    fin >> maxNumber;
    minNumber = maxNumber;
    while(fin >> number){
        if(number > maxNumber){
            maxNumber = number;
        }
        if(number < minNumber){
            minNumber = number;
        }
    }
    fout << "Max number is " << maxNumber << endl;
    fout << "Min number is " << minNumber;
    return 0;
}
