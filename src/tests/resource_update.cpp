/*
 * Test azuriranja/izmjene podesavanja korisnickog racuna
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 * 
 * Ocekivano ponasanje: 
 *                      -Odredjen broj restorana i sastojaka u restoranima vec postoji u dbase.json
 *                      -dbase.json postoji
 *                      -Te se vrsi azuriranje sastojaka
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
    sastojak.amnt=333;

    ingr jabuka;
    jabuka.name="JABUKA";
    jabuka.amnt=222;

    ingr banana;
    banana.name="BANANA";
    banana.amnt=500;

    ingr brasno;
    brasno.name="BRASNO";
    brasno.amnt=111;

    ingr secer;
    secer.name="123";
    secer.amnt=123;

    ingr VODA;
    VODA.name="VODA";
    VODA.amnt=444;

    ingr SOK;
    SOK.name="SOK";
    SOK.amnt=1;


    //Ocekivana ponasanja (za slucaj 0)
    int test=resourceUpdate("Monza","123",15);
    printf("0. %d\n",test);

    test=resourceUpdate("Monza","SOK",500);
    printf("0.8 %d\n",test);

    test=resourceUpdate("Restoran3","JABUKA",0);
    printf("0.1 %d\n",test);

    test=resourceUpdate("Restoran1","BANANA",1500);
    printf("0.2 %d\n",test);

    test=resourceUpdate("Restoran0","BRASNO",1000);
    printf("0.3 %d\n",test);

    test=resourceUpdate("Monza","SASTOJAK",1);
    printf("0.4 %d\n",test);

    //Ocekivana ponasanja za slucaj 1

    test=resourceUpdate("akjsfa","SASTOJAK",23);
    printf("1. %d\n",test);

    test=resourceUpdate("jf;","BANANA",90);
    printf("1.1 %d\n",test);

    //Ocekivana ponasanja za slucaj 2

    test=resourceUpdate("Monza","VODA",123);
    printf("2. %d\n",test);

    test=resourceUpdate("Monza","SOK",0);
    printf("2.1 %d\n",test);

    test=resourceUpdate("Restoran1","VODA",0);
    printf("2.2 %d\n",test);

    return 0;
}
