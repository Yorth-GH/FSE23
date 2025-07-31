#include "../include/datatypes.h"
#include "../include/dbase.h"

#include <iostream>
#include <string>

using namespace std;

stats getRestStats( string username ) {

	json  tmpJson;
	stats ret;

	// Proces skupljanja podataka u mapu

	ifstream file("ordersHist.json");

	json orders;
	file >> orders;

	int i = 0;
	while ( orders[ to_string(i) ] != nullptr ) {

		tmpJson = orders[to_string(i)];

		if ( tmpJson["restName"] == username ) {
			for (int j = 0; tmpJson["IDarticles"][j] != nullptr; j++) {
				( ret [ getArticleNameFromID(tmpJson["IDarticles"][j] ) ] ) ++;
			}
		}

		i++;

	}

	return ret;

}

int main() {

	checkDBase();

	order a;
	a.IDarticles = { 2, 3 };
	a.restName = "B";
	// a.artNames = { "Mejdan Fried Batak",  }
	a.price = 23; // Netačno
	a.userUName = "korikori";
	a.comment = "KOMENTAR 123";
	a.timeOrd = "23:01";
	a.timeRec = "23:23";
	a.processed = false;

	// orderCreate(a);
	// processOrder(a, true);

	// getOrderHistVector( "korikori" );

	stats st = getRestStats("B");

	for (const auto& pair : st) {
		cout << pair.first << ": " << pair.second << endl;
	}

	// std::cout << getArticleNameFromID(0) << std::endl;

}
