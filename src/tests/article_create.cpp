/*
 * Test kreiranja artikala, i njegovog kreiranja u dbase.json
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu postoji dbase.json
 *            -U folderu postoji Photo3.jpg
 * 
 * Ocekivano ponasanje: -Te se vrsi definisanje i dodavanje artikala
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
    article art1,art2,art3,art4,art5,art6,art7;

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

    //Ocekivana ponasanja : funkcija articleCreate vraca vrijednost 0

    //------------------------------------------------------------------------------------//

    vector <ingr> pice = {kola,fanta};
    vector <string> a={"tags[0],tags[0]"};

    art1.price=10.09;
    art1.name="PICE";
    art1.ingredients=pice;
    art1.tags=a;
    art1.id=2;
    art1.imagePath="imageRest.jpg";

    int test=articleCreate("Monza",art1);
    printf("0.0 %d\n",test);

    //------------------------------------------------------------------------------------//

    vector<ingr> pica={kecap,so,brasno,sir,sunka};
    vector<string> tag1={"1"};

    art2.price=20.085;
    art2.name="CAPRICOZZA";
    art2.ingredients=pica;
    art2.tags=tag1;
    art2.id=3;
    art2.imagePath="Photo1.jpg";


    test=articleCreate("Monza",art2);
    printf("0.1 %d\n",test);

    //------------------------------------------------------------------------------------//

    vector <ingr> zacin={so,biber,secer};
    vector <string> tag2={"2"};

    art3.price=15.234;
    art3.name="ZACINI";
    art3.ingredients=zacin;
    art3.tags=tag2;
    art3.id=10;
    art3.imagePath="Photo2.jpg";

    test=articleCreate("Restoran2",art3);
    printf("0.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    vector <ingr> Voda={voda};
    vector <string> tag7={"3"};

    art7.price=2.5;
    art7.name="VODA";
    art7.ingredients=Voda;
    art7.tags=tag7;
    art3.id=15;
    art3.imagePath="Photo3.jpg";

    test=articleCreate("Restoran3",art7);
    printf("0.3 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanja : funkcija articleCreate vraca vrijednost 1

    //------------------------------------------------------------------------------------//
    
    test=articleCreate("Monza",art1);
    printf("1.0 %d\n",test);

    test=articleCreate("Monza",art2);
    printf("1.1 %d\n",test);

    test=articleCreate("Restoran2",art3);
    printf("1.2 %d\n",test);

    //------------------------------------------------------------------------------------//

    //Ocekivana ponasanje : funckija articleCreate vraca vrijednost 2

    //------------------------------------------------------------------------------------//

    test=articleCreate("Nepoz23",art1);
    printf("2.0 %d\n",test);

    test=articleCreate("awjgpew23",art2);
    printf("2.1 %d\n",test);

    test=articleCreate("MONZA",art3);
    printf("2.2 %d\n",test);

    //------------------------------------------------------------------------------------//

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
