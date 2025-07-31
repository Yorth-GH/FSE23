/*
 * Test azuriranja/izmjene podesavanja korisnickog racuna
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 * 
 * Ocekivano ponasanje: 
 *                      -Odredjen broj restorana i sastojaka vec postoji u dbase.json
 *                      -Te se vrsi skidanje sastojaka
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

    //Ocekivana ponasanja (za slucaj 0)
    int test=resourceDelete("Monza","BANANA");
    printf("0. %d\n",test);

    test=resourceDelete("Restoran3","JABUKA");
    printf("0.1 %d\n",test);

    test=resourceDelete("Restoran1","BANANA");
    printf("0.2 %d\n",test);

    test=resourceDelete("Restoran0","BRASNO");
    printf("0.3 %d\n",test);

    //Ocekivana ponasanja za slucaj 1

    test=resourceDelete("akjsfa","123");
    printf("1. %d\n",test);

    test=resourceDelete("jf;","BANANA");
    printf("1.1 %d\n",test);

    //Ocekivana ponasanja za slucaj 2

    test=resourceDelete("Monza","SASTOJAK");
    printf("2. %d\n",test);

    test=resourceDelete("Restoran3","BANANA");
    printf("2.1 %d\n",test);

    test=resourceDelete("Restoran1","BRASNO");
    printf("2.2 %d\n",test);

    //TODO : Ocekivana ponasanja za slucaj 3 
    return 0;
}
/*typedef struct _article {

	double       price;        Cijena artikla 
	string       desc;         Opis atikla 
	string       imagePath;   Put do slike koja je priložena uz artikl 
	string       name;         Ime artikla 
	uiid         id;           ID artikla 
	vector<ingr> ingredients;  Sastojci koji su korišteni u artiklu 
	vector<tag>  tags;         Tag-ovi koji se vezuju za artikl

} article;
*/
