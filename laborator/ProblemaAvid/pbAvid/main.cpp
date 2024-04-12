#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
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
    fin >> cerinta;
    fin >> numbersCount;
    fin >> numarMaximDivizori;
    int numbers[numbersCount-1];
    for(int index = 0;index < numbersCount; index++){
        fin >> numbers[index];
    }
    /*for(int i = 0;i < n; i++){
        cout << v[i] << " ";
    }*/
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
        int numereInSecventa = 0;
         for(int index = 0; index <= numbersCount - 3; index++){
             int firstCmmdc = getCmmdc(numbers[index],numbers[index + 1]);
             int cmmdc = getCmmdc(firstCmmdc, numbers[index + 2]);
             int numarDivizori = getNumarDivizori(cmmdc);
             if(numarDivizori <= numarMaximDivizori){
                numereInSecventa++;
             }
             if(numarDivizori > numarMaximDivizori){
                if(numereInSecventa > secventaMaxima){
                    secventaMaxima = numereInSecventa;
                }
                numereInSecventa = 0;
             }

         }
         secventaMaxima = numereInSecventa;
         fout << secventaMaxima;
    }

    /*2. Care este lungimea maximă a unei secvențe din șirul dat, în care cel mai mare divizor comun
al oricărui triplet de numere situate pe poziții consecutive are cel mult 𝑝 divizori naturali?
*/
    return 0;
}
