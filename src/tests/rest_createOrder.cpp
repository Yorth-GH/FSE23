/*
 * Test ispravnosti orderCreate
 * Kreiramo dva restorana, stavimo neke artikle i resurse u njih
 * Poslije toga probamo da naručimo
 *
 * Kompilacija: g++, može i VSCode
 *
 * Preduslov: - U folderu NE postoji nijedan JSON fajl
 *
 * Ocekivano ponasanje:
 *   Priloženo u komentarima
 */

#include "../include/datatypes.h"
#include "../include/dbase.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;

int main() {

	checkDBase();
	checkOrdersFile();

	std::ifstream dbaseF("dbase.json");
	json dbase;
	dbaseF >> dbase;

	int exitcode1 = restRegister("rest1", "rest1111", "rest1111", "admin111", "Restoran 1", "Adresa 1");
	int exitcode2 = restRegister("rest2", "rest2222", "rest2222", "admin222", "Restoran 2", "Adresa 2");

	if (exitcode1 + exitcode2 != 0) {
		printf("Registracija naloga neuspješna!\n");
		return EXIT_FAILURE;
	}

	ingr ingrTmp1 = (ingr){ "sastojak1.1", 115 };
	ingr ingrTmp2 = (ingr){ "sastojak1.2", 10 };
	ingr ingrTmp3 = (ingr){ "sastojak1.3", 20 };

	ingr ingrTmp4 = (ingr){ "sastojak2.1", 215 };
	ingr ingrTmp5 = (ingr){ "sastojak2.2", 100 };
	ingr ingrTmp6 = (ingr){ "sastojak2.3", 5 };

	resourceCreate("rest1", ingrTmp1);
	resourceCreate("rest1", ingrTmp2);
	resourceCreate("rest1", ingrTmp3);

	resourceCreate("rest2", ingrTmp4);
	resourceCreate("rest2", ingrTmp5);
	resourceCreate("rest2", ingrTmp6);

	articleCreate(
		"rest1",
		(article) {
			15.75,
			"Opis artikla 1",
			"PUT DO SLIKE",
			"Ime artikla 1",
			0,
			{ ingrTmp1, ingrTmp2 },
			{ "Pice", "Rostilj" }
		}
	);

	articleCreate(
		"rest1",
		(article) {
			7.5,
			"Opis artikla 2",
			"PUT DO SLIKE",
			"Ime artikla 2",
			0,
			{ ingrTmp2, ingrTmp3 },
			{ "Pice", "Rostilj" }
		}
	);

	articleCreate(
		"rest2",
		(article) {
			12,
			"Opis artikla 1",
			"PUT DO SLIKE",
			"Ime artikla 1",
			0,
			{ ingrTmp4, ingrTmp5 },
			{ "Pice", "Rostilj" }
		}
	);

	articleCreate(
		"rest2",
		(article) {
			35.5,
			"Opis artikla 2",
			"PUT DO SLIKE",
			"Ime artikla 2",
			0,
			{ ingrTmp4, ingrTmp6 },
			{ "Pice", "Rostilj" }
		}
	);

	order a;

	a.price = 15.75 + 7.5 + 7.5;
	a.comment = "Slamka uz kolu!";
	a.timeOrd = "13:07";
	a.timeRec = "13:37";
	a.userUName = "korikori";

	a.IDarticles = { 0, 1, 1 };

	a.restName = "rest1";
	a.artNames = { "Ime artikla 1", "Ime artikla 2", "Ime artikla 2" };
	a.processed = false;

	// Kreiramo istu narudžbu dvaput
	orderCreate(a);
	orderCreate(a);

	processOrder(a, true);
	processOrder(a, false);

	return 0;

}
