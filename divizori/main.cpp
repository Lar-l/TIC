#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numar = 36;
    int divizorii[numar / 2 + 1];

    /*
    //Varianta pana la jumatate
    int divizor, numarDeDivizori = 0;

    cout << "Divizorii nr " << numar << " sunt:" << endl;
    divizorii[numarDeDivizori++] = 1;
    for(divizor = 2;divizor <= numar / 2;divizor++){
        if( 0 == numar % divizor  ){
            divizorii[numarDeDivizori++] = divizor;

        }
    }
    divizorii[numarDeDivizori] = numar;
    */
    //Varianta optimizata
    int numarDeDivizori = 0;
    divizorii[numarDeDivizori++] = 1;
    divizorii[numarDeDivizori++] = numar;
    for(int divizor = 2; divizor <= sqrt(numar); divizor++){
        if( 0 == numar % divizor){
            divizorii[numarDeDivizori++] = divizor;
            if(divizor != sqrt(numar)){
               divizorii[numarDeDivizori++] = numar / divizor;
            }
        }
    }
    for(int index = 0; index < numarDeDivizori; index++){
        cout << divizorii[index] << " ";
    }


    return 0;
}
