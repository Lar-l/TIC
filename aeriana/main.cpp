#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int cerinta,numarZboruri,a1,a2,h1,h2,m1,m2;
    ifstream fin("aeriana.in");
    ofstream fout("aeriana.out");
    fin >> cerinta;
    fin >> numarZboruri;
    int durataMaxima = 0;
    for(int index = 1; index <= numarZboruri; index++){
        fin >> a1 >> a2 >> h1 >> m1 >> h2 >> m2;
        int timpPlecareInMinute = h1 * 60 + m1;
        int timpSosireInMinute = h2 * 60 + m2;
        int durataZbor;
   //cout << timpPlecareInMinute << "->"<<timpSosireInMinute<<endl;
        if(timpPlecareInMinute > timpSosireInMinute){
                durataZbor = 24 * 60 - (timpPlecareInMinute - timpSosireInMinute);
        }
        if(timpPlecareInMinute < timpSosireInMinute){
                durataZbor = timpSosireInMinute - timpPlecareInMinute;
        }
        cout << durataZbor << " este durata zborului" << endl;
        if(cerinta == 1){
            if(durataZbor > durataMaxima){
                durataMaxima = durataZbor;
            }
        }
        //Cerinta 2
        if(cerinta == 2){
            int divizor;
            bool estePrim = false;
            int numarDeDivizori = 0;
            //Testare numar prim
            for( divizor = 2; divizor <= sqrt(a1); divizor++){
                if(a1 % divizor == 0){
                    numarDeDivizori++;
                  //  cout << divizor;
                }
            }

            if(numarDeDivizori == 0 && a1 > 1){
                estePrim = true;
              //  cout << a1 << " este prim" << endl;
            }
            /////////////////////////////////////////////////
            int sumaCifrelor = 0;
            if(estePrim == true){
                //Calcularea sumei cifrelor
                do{
                    int ultimaCifra = a1 % 10;
                    sumaCifrelor = sumaCifrelor + ultimaCifra;
                    a1 = a1 / 10;
                }while(a1 > 0);
            //////////////////////////////////////////////////////
               //  cout << sumaCifrelor << " este suma cifrelor" << endl;
                if(a2 % sumaCifrelor == 0){
                    int pahar = 0;
                    //int durataZborSpecial;
                    //Schimbarea valorilor intre ele
                    pahar = timpPlecareInMinute;
                    timpPlecareInMinute = timpSosireInMinute;
                    timpSosireInMinute = pahar;
                }
            }
                    /////////////////////////////////////////////////
                   // cout << timpPlecareInMinute << "->" << timpSosireInMinute << " (inversat)" << endl;

                    if(timpPlecareInMinute > timpSosireInMinute){
                        durataZbor = 24 * 60 - (timpPlecareInMinute - timpSosireInMinute);

                    }
                    if(timpPlecareInMinute < timpSosireInMinute){
                        durataZbor = timpSosireInMinute - timpPlecareInMinute;
                    }
                    //////////////////////////////////////////////////
                    //cout << "durata unui zbor special este " << durataZborSpecial << endl;

                    if(durataZbor > durataMaxima){
                        durataMaxima = durataZbor;
                    }
                    //////////////////////////////////////////////////



        }
    }

    fout << durataMaxima /60 << " " << durataMaxima % 60;

    return 0;
}
