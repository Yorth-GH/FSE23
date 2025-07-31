
/*
 * Test kreiranja korisnika
 *
 * Komanda za kompilaciju: g++ -o test.out ./create_dbase_and_user.cpp ../dbase.cpp
 *
 * Preduslov: U folderu ne postoji dbase.json
 * 
 * Ocekivano ponasanje: funkcija writeUser pravilno upisuje korisnike U i U1 u bazu
 */

#include "../include/datatypes.h"
#include "../include/dbase.h"

int main() {

	// Provjeravamo da dbase ne postoji
	checkDBase();

	user U = {
		100.0f,
		"Ulica 123",
		"Korisnik Korisniković",
		"imgPath",
		"primjer",
		"123456789",
		"korikori",
		{}
	};

	user U1 = {
		100.0f,
		"Ulica 1234",
		"Korisnik Korisnić",
		"imgPath1",
		"primjer1",
		"1234567891",
		"korikori1",
		{}
	};

	/*
	 * Ako koristimo
	 *
	 * writeUser(U);
	 * writeUser(U);
	 *
	 * onda se korisnik upisuje samo jednom.
	 * Ovo je, jednostavno, priroda biblioteke koju koristimo
	 */

	writeUser(U);
	writeUser(U1);

}

