#include <iostream>
#include <fstream>
using namespace std;
int numere[100001];

int oglindit(int n)
{
    int og = 0;
    while(n != 0){
        og = og * 10 + n % 10;
        n = n / 10;
    }
    return og;
}
int main()
{
    int cerinta , num , numarperechi = 0 ;
    ifstream fin("Perechi.in");
    ofstream fout("Perechi.out");
    fin >> cerinta;
    fin >> num;
    cout << cerinta << " " << num;
    for( int index = 1; index <= num; index++){
        fin >> numere[index];
    }
    for(int index = 1; index <= num - 1; index ++)
        for(int index2 = index + 1;index2 <= num; index2++)
            if(oglindit(numere[index])== numere[index2])
                numarperechi++;
    fout << numarperechi;
    return 0;
}
