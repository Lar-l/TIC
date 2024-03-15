#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numar;
    cin >> numar;
    bool areDivizoriPropri = false;
    bool estePrim = true;
    if(numar <= 1){
        estePrim = false;
    }
    else{
        for(int divizor = 2; divizor <= sqrt(numar); divizor++){
            if (numar % divizor == 0){
                areDivizoriPropri = true;
            }
        }
    }
    if(true == areDivizoriPropri){
        estePrim = false;
    }
    else{
        estePrim = true;
    }
    if(estePrim == true){
        cout << numar << "  este prim";
    }
    else{
        cout << numar << " nu este prim";
    }
    return 0;
}
