/*
 * Test brisanja artikala iz base (dbase.json)
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 *            -Odredjen broj restorana vec postoji u dbase.json
 *            -Odredjen broj artikala u restoranima vec postoji u dbase.json
 * 
 * 
 * Ocekivano ponasanje: 
 *                      -Vrsi se brisanje artikala
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
    //Ocekivana ponasanja : funkcija articleDelete vraca vrijednost 0

    //------------------------------------------------------------------------------------//

    int test=articleDelete("Monza","CAPRICOZZA");
    printf("0.0 %d\n",test);

    test=articleDelete("Monza","PICE");
    printf("0.1 %d\n",test);

    test=articleDelete("Restoran2","ZACINI");
    printf("0.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanja : funkcija articleDelete vraca vrijednost 1

    //------------------------------------------------------------------------------------//
    
    test=articleDelete("Monza","CAPRICOZZA");
    printf("1.0 %d\n",test);

    test=articleDelete("Monza","PICE");
    printf("1.1 %d\n",test);

    test=articleDelete("Restoran2","ZACINI");
    printf("1.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanje : funckija articleDelete vraca vrijednost 2

    //------------------------------------------------------------------------------------//

    test=articleDelete("Nepoz23","art1");
    printf("2.0 %d\n",test);

    test=articleDelete("awjgpew23","art2");
    printf("2.1 %d\n",test);

    test=articleDelete("mONZA","art3");
    printf("2.2 %d\n",test);

    //------------------------------------------------------------------------------------//


    return 0;
}
