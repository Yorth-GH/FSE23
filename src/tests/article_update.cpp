/*
 * Test azuriranja artikala
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 *            -Odredjen broj restorana vec postoji u dbase.json
 * 
 * 
 * Ocekivano ponasanje: 
 *                      -Vrsi definisanje i dodavanje artikala
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

    ingr voda,so,secer,brasno,kola,fanta,sir,sunka,kecap,biber;
    article art1,art2,art3,art4,art5,art6;

    voda.name="voda";
    voda.amnt=1;

    so.name="so";
    so.amnt=3;

    secer.name="secer";
    secer.amnt=300;

    brasno.name="brasno";
    brasno.amnt=3;

    kola.name="Coca-Cola";
    kola.amnt=10;

    fanta.name="Fanta";
    fanta.amnt=15;

    sir.name="Sir Livada";
    sir.amnt=1;

    sunka.name="Neoplanta";
    sunka.amnt=1;

    kecap.name="Kecap";
    kecap.amnt=10;

    biber.name="Biber";
    biber.amnt=15;

    //Ocekivana ponasanja : funkcija articleUpdate vraca vrijednost 0

    //------------------------------------------------------------------------------------//
    vector <ingr> pice = {kola,fanta,voda};
    vector <string> a={""};

    art1.price=1000;
    art1.name="PICE";
    art1.ingredients=pice;
    art1.tags=a;
    art1.imagePath="imageRest.jpg";

    int test=articleUpdate("Monza",art1);
    printf("0.0 %d\n",test);

    //------------------------------------------------------------------------------------//

    vector<ingr> pica={kecap,so,brasno,sir,sunka,secer};
    vector<string> tag1={"article_food,article_food,article_food,article_food,article_food,article_food"};

    art2.price=205.085;
    art2.name="CAPRICOZZA";
    art2.ingredients=pica;
    art2.tags=tag1;
    art2.imagePath="Photo1.jpg";


    test=articleUpdate("Monza",art2);
    printf("0.1 %d\n",test);

    //------------------------------------------------------------------------------------//

    vector <ingr> zacin={so,biber,secer};
    vector <string> tag2={"article_food,article_food"};

    art3.price=315.234222;
    art3.name="ZACINI";
    art3.ingredients=zacin;
    art3.tags=tag2;
    art3.imagePath="Photo2.jpg";

    test=articleUpdate("Restoran2",art3);
    printf("0.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanja : funkcija articleUpdate vraca vrijednost 1

    //------------------------------------------------------------------------------------//
    
    test=articleUpdate("Monza",art4);
    printf("1.0 %d\n",test);

    test=articleUpdate("Monza",art5);
    printf("1.1 %d\n",test);

    test=articleUpdate("Restoran2",art6);
    printf("1.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanje : funckija articleUpdate vraca vrijednost 2

    //------------------------------------------------------------------------------------//

    test=articleCreate("Nepoz23",art1);
    printf("2.0 %d\n",test);

    test=articleCreate("awjgpew23",art2);
    printf("2.1 %d\n",test);

    test=articleCreate("mONZA",art3);
    printf("2.2 %d\n",test);

    //------------------------------------------------------------------------------------//


    return 0;
}
