#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    int retinemNumarulA = a;
    int retinemNumarulB = b;
  //Algoritmul lui Euclid
  /*
    int rest = a % b;
    while(rest > 0){
        a = b;
        b = rest;
        rest = a % b;
    }
    cout << "Cmmdc: " << b;
  */
  //Algoritmul de scadere repetata
    /*while(a != b){
        if(a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    cout << "Cmmdc: " << a << endl;
    cout << "Cmmmc: " << retinemNumarulA * retinemNumarulB / a;
    return 0;
}
