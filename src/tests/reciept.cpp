#include "../include/datatypes.h"
#include "../include/dbase.h"

#include <iostream>

int main() {

	order a;

	a.price = 15.75 + 7.5 + 7.5;
	a.comment = "Slamka uz kolu!";
	a.timeOrd = "13:07";
	a.timeRec = "13:37";
	a.userUName = "korikori";

	a.IDarticles = { 0, 1, 1 };

	a.restName = "rest1";
	a.artNames = { "Ime artikla 1", "Ime artikla 2", "Ime artikla 2" };
	a.processed = true;

	std::cout << receipt(a) << std::endl;

}
