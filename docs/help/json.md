```cpp
/*
 * Ime datoteke: demo_json.cpp
 * Demo rada biblioteke nlohmann/json.hpp
 *
 * Kompilacija je moguća koristeći: g++ demo_json.cpp
 */

#include "./nlohmann/json.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json; // json.hpp
using std::cout;             // iostream
using std::endl;             // iostream
using std::ifstream;         // fstream
using std::ofstream;         // fstream
using std::string;           // string
using std::vector;           // vector

typedef struct _man {

	float height;
	int age;
	string name;
	vector<int> nums;

} man;

/*
 * Friend funkcije koje se pripisuju 'json' podatku
 * Moraju biti definisane za implicitnu serijalizaciju
 * (tj. da možemo korisitit json j = <podatak>)
 */

void to_json(json& j, const man& m) { // Pravi 'json' podatak od 'man' podatka
	j = json{
		{"height", m.height},
		{"age", m.age},
		{"name", m.name},
		{"nums", m.nums}
	};
}

void from_json(const json& j, man& m) { // Pravi 'man' podatak od 'json' podatka
	j.at("height").get_to(m.height);
	j.at("age").get_to(m.age);
	j.at("name").get_to(m.name);
	j.at("nums").get_to(m.nums);
}

int main() {

	man m;

	m.height = 1.73;
	m.age = 24;
	m.name = "Marko";
	m.nums.push_back(2);
	m.nums.push_back(3);
	m.nums.push_back(5);
	m.nums.push_back(7);

	json j = m; // Implicitna konverzija

	cout << "json j = " << j << endl; // Testni ispis 'json' podatka

	ofstream file("test.json"); // Čuvanje u fajl
	file << j;
	file.close();

	ifstream fileIN("test.json"); // Čitanje iz fajla
	json jIN = json::parse(fileIN);
	fileIN.close();

	cout << "json jIN = " << jIN << endl;

	return EXIT_SUCCESS;

}
```

Više podataka je [ovde](https://github.com/nlohmann/json).
