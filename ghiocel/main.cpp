#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cerinta = 0;
    int numarBuchete = 0;
    ifstream fisierDeIntrare("ghiocel.in");
    ofstream fisierDeIesire("ghiocel.out");
    int numereUrcus = 0;
    int numereCoboras = 0;
    int numereDeal = 0;
    int numereVale = 0;
    fisierDeIntrare >> cerinta;
    fisierDeIntrare >> numarBuchete;
    int buchete[numarBuchete];
    int buchet;
    for(int index = 0;index < numarBuchete;index++){
        fisierDeIntrare >> buchet;
        buchete[index] = buchet;
    }

        for(int index = 0;index < numarBuchete; index++){
            int numarDeVerificat = buchete[index];
            //de completat
            int cat = 0;
            int numarCifre = 0;
            int impartitor = 10;
            do{
                cat= numarDeVerificat / impartitor;
                impartitor = impartitor * 10;
                numarCifre++;

            }while(cat > 0);
            //cout << numarCifre;
            int cifre[numarCifre];
            impartitor = 10;
            cifre[0] = numarDeVerificat % impartitor;
            for(int indexCifra = 1; indexCifra < numarCifre;indexCifra++ ){
                cat = numarDeVerificat / impartitor;
                cifre[indexCifra] = cat % 10;
                impartitor = impartitor * 10;
            }
            if(1 == cerinta){

                bool numarulEsteUrcus = true;
                for(int indexCifra = numarCifre - 1;indexCifra > 0; indexCifra--){
                    //cout << cifre[indexCifra] << " ";
                    if (cifre[indexCifra] > cifre[indexCifra - 1]){
                        numarulEsteUrcus = false;
                    }
                }
                if(true == numarulEsteUrcus){
                    numereUrcus++;
                }

            }
            if(2 == cerinta){

                bool numarulEsteCoboras = true;
                for(int indexCifra = numarCifre - 1;indexCifra > 0; indexCifra--){
                    //cout << cifre[indexCifra] << " ";
                    if (cifre[indexCifra] < cifre[indexCifra - 1]){
                        numarulEsteCoboras = false;
                    }
                }
                if(true == numarulEsteCoboras){
                    numereCoboras++;
                }

            }

            if(4 == cerinta){
                bool trebuieVerificatCrestere = false;
                bool esteVale= false;
                bool esteCrestere = true;
                bool esteDescrestere = true;
                for(int indexCifra = numarCifre - 1;indexCifra > 0; indexCifra--){
                    //cout << cifre[indexCifra] << " ";
                     if (cifre[indexCifra] < cifre[indexCifra - 1]){
                        esteDescrestere = false;
                     }
                     if(esteDescrestere == true){
                        trebuieVerificatCrestere = true;
                     }
                     if(false == trebuieVerificatCrestere){
                        if (cifre[indexCifra] < cifre[indexCifra - 1]){
                            trebuieVerificatCrestere = true;
                        }
                    }
                    if(true == trebuieVerificatCrestere){
                        if (cifre[indexCifra] > cifre[indexCifra - 1]){
                            esteCrestere = false;

                        }
                    }
                }
                if(esteCrestere == true;esteDescrestere == true){
                    numereVale++;
                }
            }

        }
        if(1 == cerinta){
            fisierDeIesire << numereUrcus;
        }

        if(2 == cerinta){
            fisierDeIesire << numereCoboras;
        }
        if(3 == cerinta){
            fisierDeIesire << numereDeal;
        }
        if(4 == cerinta){
                fisierDeIesire << numereVale;
        }



    return 0;
}






/*
    Problema Ghiocel
Fișier de intrare ghiocel.in
Fișier de ieșire ghiocel.out
Ghiocel, nepotul cel mai mic al Babei Dochia, este elev în clasa a V-a și dorește să ofere câte un
buchet de ghiocei fiecăreia dintre cele 𝑛 doamne profesoare. Primul buchet va avea 𝑏1 ghiocei, cel
de-al doilea buchet va avea 𝑏2 ghiocei, cel de-al treilea buchet va avea 𝑏3 ghiocei, și așa mai departe,
iar ultimul buchet, cel de al 𝑛-lea, va avea 𝑏𝑛 ghiocei.
Copilul dorește să afle câte dintre numerele 𝑏1, 𝑏2, ... , 𝑏𝑛 au aspect de urcuș, coborâș, deal sau vale.
Spunem că un număr natural nenul are aspect de urcuș, dacă cifrele sale apar în ordine strict crescătoare, de la stânga la dreapta. De exemplu, numărul 2346 are aspect de urcuș.
Spunem că un număr natural nenul are aspect de coborâș, dacă cifrele sale apar în ordine strict
descrescătoare, de la stânga la dreapta. De exemplu, numărul 520 are aspect de coborâs.
Spunem că un număr natural nenul are aspect de deal dacă cifrele sale se succed întâi în ordine
strict crescătoare, apoi în ordine strict descrescătoare. De exemplu numărul 135421 are aspect de
deal.
Spunem că un număr natural nenul are aspect de vale dacă cifrele sale se succed întâi în ordine
strict descrescătoare, apoi în ordine strict crescătoare. De exemplu numărul 210345 are aspect de
vale.
Cerințe
Cunoscând numărul 𝑛 de buchete, iar pentru fiecare buchet 𝑖 (1 ≤ 𝑖 ≤ 𝑛), numărul 𝑏𝑖 de ghiocei,
determinați, în funție de valoarea unei valori date 𝑐 (cerința), câte dintre numerele 𝑏𝑖 au aspect de
urcuș, sau câte au aspect de coborâș, sau câte au aspect de deal sau câte au aspect de vale.
Date de intrare
Prima linie a fișierului ghiocel.in conține două numere naturale 𝑐 și 𝑛, separate prin spațiu, care
reprezintă cerința și numărul de buchete de ghiocei. Pe linia a doua se află valorile 𝑏1, 𝑏2, ..., 𝑏𝑛,
separate prin câte un spațiu.
Date de ieșire
În fișierul ghiocel.out se va scrie un singur număr natural. Acest număr reprezintă numărul de
valori urcuș din șirul 𝑏 dacă avem 𝑐 = 1, numărul de valori coborâș dacă avem 𝑐 = 2, numărul de
valori deal dacă avem 𝑐 = 3 respectiv numărul de valori vale dacă avem 𝑐 = 4.
Restricții
• 1 ≤ 𝑐 ≤ 4.
• 1 ≤ 𝑛 ≤ 100 000.
• Fiecare număr 𝑏𝑖
, (1 ≤ 𝑖 ≤ 𝑛) este cuprins între 10 și 2 000 000 000 inclusiv.
    */
