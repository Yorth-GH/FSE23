/*
 * Test azuriranja/izmjene podesavanja korisnickog racuna
 *
 * Kompilacija: VSCode
 *
 * Preduslov: -U folderu ne postoji dbase.json
 * 
 * Ocekivano ponasanje: 
 *                      -Niz korisnika se upisuje u dbase.json funkcijom userRegister
 *                      -Ocekivana povratna vrijednost: 0
 *                      
 */

#include "../include/datatypes.h"
#include "../include/dbase.h"
#include <cstdio>

int main()
{
    checkDBase();

    int user0 = userRegister("Mile","123","123","066014013","Mile Korisnik","Ulica Sime");
    int user2 = userRegister("Kore","444","444","066314013","Kore Korisnik","Ulica Kore");
    int user3 = userRegister("Dore","555","555","066214013","Dore Korisnik","Ulica Dore");
    int user4 = userRegister("Lere","777","777","066114013","Lere Korisnik","Ulica Lere");


    //Ocekivano ponasanje: userUpdate vraca 0
    int test=userUpdate("Mile","Ulica Sime","Mile Korisnik","1234","123","066014013");
    printf("0. %d\n",test);

    //Ocekivano ponasanje: userUpdate vraca 1
    test=userUpdate("Mile","Ulica Sime R","Mile Korisnik","123456789","123","066014013");
    printf("1. %d\n",test);

    //Ocekivano ponasanje: userUpdate vraca 2

    test=userUpdate("Lere","Ulica Lere","Lere Korisnik","777","777","0667883 99");
    printf("2. %d\n",test);

    //Ocekivano ponasanje: userUpdate vraca 4
    test=userUpdate("Dorem","Ulica Dore","Dore Korisnik","NovaLozinka","555","066214013");
    printf("4. %d\n",test);

    //Ostali testovi, ocekivana ponasanja (za slucaj 2):

    test=userUpdate("Lere","Ulica Lere","Lere Korisnik","NovaLozinka","777","a");
    printf("2. %d\n",test);

    test=userUpdate("Lere","Ulica Lere","Lere Korisnik","NovaLozinka","777","abcdef");
    printf("2. %d\n",test);

    test=userUpdate("Dore","Ulica Dore","Dore Korisnik","555","555"," 066214013");
    printf("2. %d\n",test);

    test=userUpdate("Dore","Ulica Dore","Dore Korisnik","555","555","06a6214013");
    printf("2. %d\n",test);

    //Ostali testovi, ocekivana ponasanja (za slucaj 1):

    test=userUpdate("Dore","Ulica Dore","Dore Korisnik","555","5550","000");
    printf("1. %d\n",test);

    test=userUpdate("Mile","Ulica Sime","Mile Korisnik","1234","1234a","06214013");
    printf("1. %d\n",test);


    return 0;
}
