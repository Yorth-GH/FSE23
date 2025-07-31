/*
 * Test azuriranja/izmjene podesavanja restoranskog racuna
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu ne postoji dbase.json
 *            -U folderu postoji restPhoto.txt
 *            -U folderu postoji imagePath.jpg
 * 
 * Ocekivano ponasanje: 
 *                      -Niz restorana se upisuje u dbase.json funkcijom userRegister
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


    int rest0=restRegister("Restoran0","pasvord","pasvord","pasvord","Restoran Banja Luka","Ulica Nulta");
    int rest1=restRegister("Restoran1","zaporka","zaporka","zaporka","Restoran Banja Luka","Ulica Prva");
    int rest2=restRegister("Restoran2","lozinka","lozinka","lozinka","Restoran Banja Luka","Ulica Druga");
    int rest3=restRegister("Restoran3","pas23wpr0*","pas23wpr0*","pas23wpr0*","Restoran Banja Luka","Ulica Treca");
    int rest4=restRegister("Monza","pas","pas","pas","Monza","Adresa");
    int rest5=restRegister("monz32","123","123","123","Amadeus","Ulica Mome Robi 2");

    vector <string> tags={"Tjestenina"};
    vector <string> tags1={"Spasnka","Srpska","Brazilsa","Italijanksa","Francuska"};
    vector <string> tags2={"Pomfri","Kupus","Cevapi"};

    workTime wt={"09:00","20:00"};
    workTime wt1={"32:00","52:00"};
    workTime wt2={"07:00","21:00"};
    workTime wt3={"14:00","13:00"};
    workTime wt4={"07:60","19:99"};

    //Ocekivano ponasanje: restUpdate vraca vrijednost 0
    int test=restUpdate("Restoran0","Ulica Nulta","Deskripcija","restPhoto.txt","pasvord","pasvord","pasvord",tags,wt);
    printf("0. %d\n",test);

    //Ocekivano ponasanje: restUpdate vraca vrijednost 1
    test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt","pasvord","pasvord","pasVord",tags,wt);
    printf("1. %d\n",test);

    //Ocekivano ponasanje: restUpdate vraca vrijenost 2
    test=restUpdate("Dalipostojim","Ulica Prva","","restPhoto.txt","1","1","1",tags,wt);
    printf("2. %d\n",test);

    //Ocekivano ponasanje: restUpdate vraca vrijednost 3
    test=restUpdate("Restoran3","Ulica Peta","Divan mali restoran","123.txt","pas23wpr0*","pas23wpr0*","pas23wpr0*",tags,wt);
    printf("3. %d\n",test);

    //Ocekivano ponasanje: restUpdate vraca vrijednost 4
    test=restUpdate("Restoran2","Ulica Rade","Objection","restPhoto.txt","lozinka","lozinka","lozinka",tags,wt1);
    printf("4. %d\n",test);

    //Ostali testovi, ocekivana ponasanja(za slucaj 1):

    test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt","pasvord","pasvord"," pasvord",tags1,wt2);
    printf("1.1 %d\n",test);

    test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt"," pasvord","pasvord","pasvord",tags2,wt2);
    printf("1.2 %d\n",test);

    test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt","PASVORD","pasvord","pasvord",tags1,wt2);
    printf("1.3 %d\n",test);

    test=restUpdate("Restoran0","Ulica Nulta","Deskrip233232tion","restPhoto.txt","pasvord","pasvord"," pasvord",tags,wt3);
    printf("1.4 %d\n",test);

    test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt","pasvord","PASVORD","pasvord",tags2,wt3);
    printf("1.5 %d\n",test);

    //test=restUpdate("Restoran0","Ulica Nulta","Deskription","restPhoto.txt","pasvord","PASVORD","PASVORD",tags2,wt3);
    //printf("1.6 %d\n",test);

    test=restUpdate("Monza","Adresa","123","restPhoto.txt","pas","PAS","pas",tags1,wt);
    printf("1.7 %d\n",test);

    //Ostali testovi, ocekivana ponasanja (za slucaj 2,3,4)
    test=restUpdate("Akademija","Adress","Desc","restPhoto.txt","123","123","123",tags,wt);
    printf("2.1 %d\n",test);

    test=restUpdate("monz32","Ulica Mome Robi 2","Dec","imagePath.jpg","123","123","123",tags2,wt3);
    printf("3.1 %d\n",test);

    test=restUpdate("monz32","Ulica Mome Robi 2","Dec","imageRest.jpg","123","123","123",tags2,wt4);
    printf("4.1 %d\n",test);

    return 0;
}
