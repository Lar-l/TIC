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
int nrcifre(int n)
{
    int nrc = 0;
    while(n != 0){
        nrc++;
        n = n /10;
    }
    return nrc;
}
int lipire(int a ,int b)
{
    int lipire;
    int c = b;
    while(b != 0){
        b = b / 10;
        a = a * 10;

    }
    lipire = a + c;
}
int main()
{
    int cerinta , num , numarperechi = 0 ,maxx = 0;
    ifstream fin("Perechi.in");
    ofstream fout("Perechi.out");
    fin >> cerinta;
    fin >> num;
    if (cerinta == 1){
        for( int index = 1; index <= num; index++){
            fin >> numere[index];
        }
        for(int index = 1; index <= num - 1; index ++)
            for(int index2 = index + 1;index2 <= num; index2++)
                if(oglindit(numere[index])== numere[index2] && oglindit(numere[index2]) == numere[index] && numere[index] != numere[index2])
                {
                    //cout<<index<<endl;
                    numarperechi++;
                    //cout << numere[index] << "-" << numere[index2]<<endl;
                }
        fout << numarperechi;
    }
    if(cerinta == 2){
        for( int index = 1; index <= num; index++){
            fin >> numere[index];
         for(int index = 1; index <= num - 1; index ++)
            for(int index2 = index + 1;index2 <= num; index2++){
                int nrlipit = lipire(numere[index],numere[index2]);
                if( oglindit(nrlipit) == nrlipit)
                    if(nrlipit > maxx )
                        maxx = nrlipit;
                nrlipit = lipire(numere[index2],numere[index]);
                if( oglindit(nrlipit) == nrlipit)
                    if(nrlipit > maxx )
                        maxx = nrlipit;
            }
        }
    }
    fout << maxx;

    return 0;
}
