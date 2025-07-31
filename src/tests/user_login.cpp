/*
 * Test registracija, ulogovanja i brisanja korisnika
 * Test registracija, ulogovanja i brisanja restorana
 *
 * Kompilacija: VSCode
 *
 * Preduslov: dbase.json ne postoji
 * 
 *                      
 */

#include "../include/datatypes.h"
#include "../include/dbase.h"
#include <cstdio>

int main(){
    //Provjera da li dbase.json postoji
    checkDBase();

    printf("Testiranje funkcije userRegister: ");
    

    //Upis korisnika u dbase.json
    //Ocekivano ponasanje: userRegister vraca vrijednost 0
    int a = userRegister("korikori", "primjer", "primjer", "123456789", "Korisnik Korisnikovic", "Ulica 123");
    printf("%d ", a);

    //Ocekivano ponasanje: userRegister vraca vrijednost 1
    a = userRegister("korikori", "primjer2", "primjer2", "1234567892", "Korisnik Korisnikovic2", "Ulica 1234");
    printf("%d ", a);

    //Ocekivano ponasanje: userRegister vraca vrijednost 2 (lozinke se ne poklapaju)
    a = userRegister("korikori2", "primjer", "primjer2", "123456789", "Korisnik Korisnikovic", "Ulica 123");
    printf("%d\n", a);

    printf("Testiranje funkcije userLogin: ");
    //Ocekivano ponasanje: userLogin vraca vrijednost 0 
    a = userLogin("korikori", "primjer");
    printf("%d ", a);

    //Ocekivano ponasanje: userLogin vraca vrijednost 1
    a = userLogin("kori", "primjer");
    printf("%d ", a);

    //Ocekivano ponasanje: userLogin vraca vrijednost 2
    a = userLogin("korikori", "asdf");
    printf("%d\n", a);

    printf("Testiranje funkcije restRegister: ");
    //Ocekivano ponasanje: restRegister vraca vrijednost 0
    a = restRegister("Restoran1", "lozinka1", "lozinka1", "lozinka2", "MCD", "adresa1");
    printf("%d ", a);

    //Ocekivano ponasanje: restRegister vraca vrijednost 1
    a = restRegister("Restoran1", "lozinka2", "lozinka2", "lozinka2", "BurgerPrince", "adresa2");
    printf("%d ", a);

    //Ocekivano ponasanje: restRegister vraca vrijednost 2
    a = restRegister("Restoran2", "lozinka3", "lozinka4", "lozinka3", "MCD", "adresa1");
    printf("%d\n", a);

    printf("Testiranje funkcije restLogin: ");
    //Ocekivano ponasanje: restLogin vraca vrijednost 0
    a = restLogin("Restoran1", "lozinka1");
    printf("%d ", a);

    //Ocekivano ponasanje: restLogin vraca vrijednost 1
    a = restLogin("Restoran2", "lozinka1");
    printf("%d ", a);

    //Ocekivano ponasanje: restLogin vraca vrijednost 2
    a = restLogin("Restoran1", "lozinka2");
    printf("%d\n", a);

    printf("Testiranje funkcije userRemove: ");
    //Ocekivano ponasanje: userRemove vraca vrijednost 1
    a = userRemove("Korisnik9", "Korisnik9", "lozinka1");
    printf("%d ", a);

    //Ocekivano ponasanje: userRemove vraca vrijednost 2
    a = userRemove("korikori", "korikori", "123456789");
    printf("%d ", a);

    //Ocekivano ponasanje: userRemove vraca vrijednost 3
    a = userRemove("korikori", "Korisnik9", "123456789");
    printf("%d ", a);

    //Ocekivano ponasanje: userRemove vraca vrijednost 0
    a = userRemove("korikori", "korikori", "primjer");
    printf("%d\n", a);

    printf("Testiranje funkcije restRemove: ");
    //Ocekivano ponasanje: restRemove vraca vrijednost 1
    a = restRemove("RandomRestoran", "RandomRestoran", "lozinka2");
    printf("%d ", a);

    //Ocekivano ponasanje: restRemove vraca vrijednost 2
    a = restRemove("Restoran1", "Restoran1", "netacnaLozinka");
    printf("%d ", a);

    //Ocekivano ponasanje: restRemove vraca vrijednost 3
    a = restRemove("Restoran1", "netacanUsername", "lozinka2");
    printf("%d ", a);

    //Ocekivano ponasanje: restRemove vraca vrijednost 0
    a = restRemove("Restoran1", "Restoran1", "lozinka2");
    printf("%d\n", a);

    return 0;

}
