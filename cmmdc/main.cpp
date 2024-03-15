#include <iostream>

using namespace std;

int main()
{
    int a=64, b=100;
    int cmmdc;
   /*
    //Algoritmul lui Euclid
    int rest = a % b;
    while(rest != 0){
        a = b;
        b = rest;
        rest = a % b;
    }
    cmmdc = b;


    */
    //Scaderi repetate
    while(a != b){
        if(a > b){
            a = a - b;
        }
        if(b > a){
            b = b - a;
        }
    }
    .cmmdc = a;
    cout << "cmmdc: " << cmmdc;
    return 0;
}
