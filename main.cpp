#include <iostream>
#include <fstream>

using namespace std;
unsigned int fr[10000];
unsigned int oglindit(unsigned int n)
{
    unsigned int ogl = 0;
    while(n > 0){
        ogl = ogl * 10 + n % 10;
        n = n / 10;
    }
    return ogl;
}
int main()
{
    ifstream fin("perechi.in");
    ofstream fout("perechi.out");
    unsigned int n, c ,s = 0, nrogl;
    fin >> c >> n;
    if(c == 1){
        for(unsigned int i = 0;i < n; i++){
           unsigned int a;
           fin >> a;
           fr[a]++;
        }
        for(unsigned int i = 12; i < 9999; i++){
            if(fr[i] != 0)
                nrogl = oglindit(i);
            if(oglindit(nrogl) == i && nrogl > i){
               s = s + fr[i] * fr[nrogl];
            }
        }
        fout << s;

    }
    return 0;
}
