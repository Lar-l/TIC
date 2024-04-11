#include <iostream>

using namespace std;

int main()
{
    int numar,ultimaCifra;
    int indexCifra = 0;
    int cifre[20];
    cin >> numar;
    do{
        ultimaCifra = numar % 10;
        cifre[indexCifra] = ultimaCifra;
        numar = numar / 10;
        indexCifra++;
    }while(numar > 0);
    for(int index = indexCifra - 1; index >= 0; index--){
        cout << cifre[index] << " ";
    }
    return 0;
}
