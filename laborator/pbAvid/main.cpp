#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int sirp[3000], lsirp = 0;

int getCmmdc(int a, int b)
{
    int rest;
    while(b > 0){
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}
int prim(int n)
{
    if(n <= 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if( n % 2 == 0){
        return 0;
    }
    for( int i = 3; i * i <= n; i = i + 2){
        if( n % i == 0){
            return 0;
        }
    }
    return 1;
}
void sirprime()
{
    for(int i = 2; i * i < 5000000; i++){
        if( prim(i)){
            lsirp ++;
            sirp[lsirp] = i;
        }
    }
}
int getNumarDivizori(int a)
{
    int nrDiv = 2;
    int divizor;
    for( divizor = 2; divizor < sqrt(a); divizor ++){
        if(a % divizor == 0 ){
            nrDiv = nrDiv + 2;
        }

    }
    if( divizor * divizor == a){
        nrDiv++;
     }
    return nrDiv;
}
int main()
{
    int numbersCount, numarMaximDivizori, cerinta;
    ifstream fin("avid.in");
    ofstream fout("avid.out");
    sirprime();
    for(int i = 1; i <= lsirp; i++){
        cout << sirp[i] << " ";
    }
    fin >> cerinta;
    fin >> numbersCount;
    fin >> numarMaximDivizori;
    int numbers[numbersCount-1];
    for(int index = 0;index < numbersCount; index++){
        fin >> numbers[index];
    }
    int numarTriplete = 0;
    if(cerinta == 1){
        for(int index = 0; index <= numbersCount - 3; index++){
            int firstCmmdc = getCmmdc(numbers[index],numbers[index + 1]);
            int cmmdc = getCmmdc(firstCmmdc, numbers[index + 2]);
            int numarDivizori = getNumarDivizori(cmmdc);
            if(numarDivizori <= numarMaximDivizori){
                numarTriplete++;
            }
        }
        fout << numarTriplete;
    }
    if(cerinta == 2){
        int secventaMaxima = 0;
        int numereInSecventa = 2;
        for(int index = 0; index <= numbersCount - 3; index++){
             int firstCmmdc = getCmmdc(numbers[index],numbers[index + 1]);
             int cmmdc = getCmmdc(firstCmmdc, numbers[index + 2]);
             int numarDivizori = getNumarDivizori(cmmdc);
             if(numarDivizori <= numarMaximDivizori){
                numereInSecventa++;
             }
             else{
                numereInSecventa = 2;
             }
             if(numereInSecventa > secventaMaxima){
                secventaMaxima = numereInSecventa;
             }
        }
        if(secventaMaxima == 2){
            secventaMaxima = 0;
         }
        fout << secventaMaxima;
    }
    return 0;
}
