/*
 * Test azuriranja/izmjene podesavanja korisnickog racuna
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 * 
 * Ocekivano ponasanje: 
 *                      -Odredjen broj restorana vec postoji u dbase.json
 *                      -Te se vrsi ubacivanje sastojaka
 *                      -Ocekivana povratna vrijednost: 0
 *                      
 */

#include "../include/datatypes.h"
#include "../include/dbase.h"
#include <cstdio>
#include <vector>

int main()
{
    checkDBase();

    ingr sastojak;
    sastojak.name="SASTOJAK";
    sastojak.amnt=100;

    ingr jabuka;
    jabuka.name="JABUKA";
    jabuka.amnt=1;

    ingr banana;
    banana.name="BANANA";
    banana.amnt=5;

    ingr brasno;
    brasno.name="BRASNO";
    brasno.amnt=5;

    ingr secer;
    secer.name="123";
    secer.amnt=500000;

    //Ocekivana ponasanje: funkcija resouceCreate vraca vrijednost 0
    int test=resourceCreate("Monza",sastojak);
    printf("0. %d\n",test);

    test=resourceCreate("Restoran3",jabuka);
    printf("0.1 %d\n",test);

    test=resourceCreate("Restoran1",banana);
    printf("0.2 %d\n",test);

    test=resourceCreate("Restoran0",brasno);
    printf("0.3 %d\n",test);

    test=resourceCreate("Monza",secer);
    printf("0.4 %d\n",test);

    //Ocekivana ponasanja za slucaj 1

    test=resourceCreate("Monza",sastojak);
    printf("1. %d\n",test);

    test=resourceCreate("Monza",banana);
    printf("1.1 %d\n",test);

    test=resourceCreate("Monza",brasno);

    //Ocekivana ponasanja za slucaj 2

    test=resourceCreate("akjsfa",sastojak);
    printf("2. %d\n",test);

    test=resourceCreate("jf;",banana);
    printf("2.1 %d\n",test);

    return 0;
}
