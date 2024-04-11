#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
int cmmdc(int a, int b)
{
    int rest;
    while(b > 0){
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}
int nrdiv(int a)
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
    int n, p, c;
    ifstream fin("avid.in");
    fin >> c;
    fin >> n;
    fin >> p;
    int v[n-1];
    for(int i = 0;i < n; i++){
        fin >> v[i];
    }
    /*for(int i = 0;i < n; i++){
        cout << v[i] << " ";
    }*/




    return 0;
}
