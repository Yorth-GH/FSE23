#include "include/dbase.h"
#include <string>
#include <vector>
#include <sstream> // std::stringstream
#include <iostream>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <windows.h>
#include <WinUser.h>

#define dbRestCurrUser dbase["RESTS"][username]

using it = json::iterator;
using std::stringstream;
using std::endl;
using std::cout;
using std::unordered_map;
using std::sort;
using std::to_string;

string profileImagePath = "";
string activeUser = "";
bool auth = false;

vector<string> articleTags = { "Pice", "Rostilj", "Tjestenina", "Pizza", "Vegansko", "Burger", "Salata", "Ljuto", "Slatko" };

vector<string> getArticleTags() { return articleTags; }

string getProfileImagePath() { return profileImagePath; }
void   setProfileImagePath(string arg) { profileImagePath = arg; }

bool getAuth() { return auth; }
void setAuth(bool arg) { auth = arg; }

string getActiveUser() { return activeUser; }
void   setActiveUser(string arg) { activeUser = arg; }

// RESTORAN MORA DA POSTOJI
string getArticleNameFromID(unsigned int id) {

	ifstream file("dbase.json");
	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];

	for (auto& curRest : rests) {
		json articles = curRest["articles"];

		for (auto& article : articles.items()) {
			json articleData = article.value();
			if (articleData["id"] == id) {
				return article.key();  // Return the article name
			}
		}
	}

	return "Artikl ne postoji";  // Article not found

}

/* Petar: Ovo je Peri, za broj puta koji se artikl naruči */
vector<string> peroArtikliIme;
vector<int>    peroArtikliPuta;
void peroArtikliConvertOrderToVec(order orderr) {

	peroArtikliIme.clear();
	peroArtikliPuta.clear();

	unordered_map<string, int> mapp;
	for ( int id : orderr.IDarticles ) {
		mapp[getArticleNameFromID(id)]++;
	}

	for ( auto kv : mapp ) {
		peroArtikliIme.push_back(kv.first);
		peroArtikliPuta.push_back(kv.second);
	}

}

vector<string> getPeroArtikliIme() { return peroArtikliIme; }
vector<int> getPeroArtikliPuta() { return peroArtikliPuta; }

void userToJson(json& j, const user& m)
{
	j["USERS"][m.username]["password"] = m.password;
	j["USERS"][m.username]["fullName"] = m.fullName;
	j["USERS"][m.username]["address"] = m.address;
	j["USERS"][m.username]["phone"] = m.phone;
	j["USERS"][m.username]["imagePath"] = m.imagePath;
	j["USERS"][m.username]["balance"] = m.balance;
	//TODO: dodati order history kad se implementira
}

void restToJson(json& j, const rest& m)
{
	j["RESTS"][m.username]["password"] = m.password;
	j["RESTS"][m.username]["passwordAd"] = m.passwordAd;
	j["RESTS"][m.username]["address"] = m.address;
	j["RESTS"][m.username]["imagePath"] = m.imagePath;
	j["RESTS"][m.username]["name"] = m.name;
	j["RESTS"][m.username]["desc"] = m.desc;
	j["RESTS"][m.username]["worktime"]["open"] = m.wt.timeOpen;
	j["RESTS"][m.username]["worktime"]["close"] = m.wt.timeClose;

	for (int i = 0; i < m.tags.size(); i++)
		j["RESTS"][m.username]["tags"][i] = m.tags.at(i);

	for (int i = 0; i < m.inventory.size(); i++)
		j["RESTS"][m.username]["ingr"][m.inventory.at(i).name] = m.inventory.at(i).amnt;

	//TODO: dodati article ID-ove
}

void writeUser(const user& userr)
{
	json j;
	ifstream dbasein("dbase.json");
	dbasein >> j;
	dbasein.close();
	// cita iz database-a u buffer

	ofstream dbase("dbase.json");
	userToJson(j, userr);
	dbase << j.dump(4);
	dbase.close();
	// dodaje korisnika na kraj buffera i upisuje u database
}

void writeRest(const rest& restt)
{
	json j;
	ifstream dbasein("dbase.json");
	dbasein >> j;
	dbasein.close();
	// cita iz database-a u buffer

	ofstream dbase("dbase.json");
	restToJson(j, restt);
	dbase << j.dump(4);
	dbase.close();
	// dodaje restoran na kraj buffera i upisuje u database
}

vector<uiid> parseArticleIDsFromRest(string username)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	vector<uiid> ids;
	uiid id;

	for (it i = rests[username]["articles"].begin(); i != rests[username]["articles"].end(); i++)
	{
		id = rests[username]["articles"][i.key()]["id"];
		ids.push_back(id);
	}

	return ids;
}

vector<rest> parseRestsFromDBase()
{
	vector<rest> restVec;
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];

	for (it i = rests.begin(); i != rests.end(); i++)
		restVec.push_back(restGet(i.key()));

	return restVec;
}

vector<user> parseUsersFromDBase()
{
	vector<user> userVec;
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json users = dbase["USERS"];

	for (it i = users.begin(); i != users.end(); i++)
		userVec.push_back(userGet(i.key()));

	return userVec;
}

vector<article> parseArticlesFromRest(string username)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	vector<article> articles;
	article art;

	for (it i = rests[username]["articles"].begin(); i != rests[username]["articles"].end(); i++)
	{
		art.name = i.key();
		art.desc = rests[username]["articles"][i.key()]["desc"];
		art.id = rests[username]["articles"][i.key()]["id"];
		art.imagePath = rests[username]["articles"][i.key()]["imagePath"];
		art.price = rests[username]["articles"][i.key()]["price"];
		art.tags = rests[username]["articles"][i.key()]["tags"];

		for (it j = rests[username]["articles"][i.key()]["ingredients"].begin(); j != rests[username]["articles"][i.key()]["ingredients"].end(); j++)
		{
			ingr ing;
			ing.name = j.key();
			ing.amnt = j.value();
			art.ingredients.push_back(ing);
		}

		articles.push_back(art);
	}

	return articles;
}

// Ovo vraća sve artikle KOJI MOGU DA SE NAPRAVE
vector<article> parseArticlesFromRestSpecial(string username)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	vector<article> articles;
	article art;

	bool dodajeSe;

	for (it i = rests[username]["articles"].begin(); i != rests[username]["articles"].end(); i++)
	{

		cout << "RADIMO SA ARTIKLOM " << i.key() << endl;

		art.name = i.key();
		art.desc = rests[username]["articles"][i.key()]["desc"];
		art.id = rests[username]["articles"][i.key()]["id"];
		art.imagePath = rests[username]["articles"][i.key()]["imagePath"];
		art.price = rests[username]["articles"][i.key()]["price"];
		art.tags = rests[username]["articles"][i.key()]["tags"];

		// Dostupan:
		// u restoranu postoji dovoljno sastojaka da se napravi barem jedan
		//
		// uđeš u restoran (rests[username]) i ideš kroz artikle (to je već urađeno)
		// ideš kroz sastojke svakog artikla, nađeš te sastojke u restoranu, i porediš
		// ako ijednog ima manje nego potrebno, ako ima, continue;

		dodajeSe = true;

		for (
			it j = rests[username]["articles"][i.key()]["ingredients"].begin();
			j != rests[username]["articles"][i.key()]["ingredients"].end();
			j++
			) {

			

			ingr ing;
			ing.name = j.key();

			int uRestoranu = rests[username]["ingr"][ing.name];
			int potrebno = (*i)["ingredients"][ing.name];

			if (uRestoranu < potrebno) 
				dodajeSe = false;

			ing.amnt = j.value();
			art.ingredients.push_back(ing);
		}

		if (dodajeSe) articles.push_back(art);

	}

	return articles;
}

int userLogin(string username, string passwordPureText)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json users = dbase["USERS"];
	if (users.contains(username))
	{
		SHA1 sha;
		sha.update(passwordPureText);
		string result = sha.final();
		json password = dbase["USERS"][username]["password"];
		if (password == result)
			return 0;
		else
			return 2;
	}
	return 1;

}

int restLogin(string username, string passwordPureText)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (rests.contains(username))
	{
		SHA1 sha;
		sha.update(passwordPureText);
		string result = sha.final();
		json password = dbase["RESTS"][username]["password"];
		if (password == result)
			return 0;
		else
			return 2;
	}
	return 1;

}

int userRegister(string username, string passwordPureText, string confirmPassword, string phone, string fullName, string address)
{
	if (passwordPureText != confirmPassword)
		return 2;

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json users = dbase["USERS"];
	if (users.contains(username))
		return 1;

	SHA1 sha;
	sha.update(passwordPureText);
	string result = sha.final();

	user m;
	m.username = username;
	m.password = result;
	m.balance = 0; // DEFAULT
	m.address = address;
	m.fullName = fullName;
	m.phone = phone;
	m.imagePath = ""; // TODO: Hoćemo li raditi slike?
	
	writeUser(m);

	return 0;
}

int restRegister(string username, string passwordPureText, string confirmPassword, string passwordAdPureText, string name, string address)
{
	if (passwordPureText != confirmPassword)
		return 2;

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (rests.contains(username))
		return 1;

	SHA1 sha;
	sha.update(passwordPureText);
	string result = sha.final();
	sha.update(passwordAdPureText);
	string result2 = sha.final();

	vector<string> tags;
	vector<ingr> ings;
	tags.push_back("");
	rest m;
	m.username = username;
	m.password = result;
	m.address = address;
	m.passwordAd = result2;
	m.imagePath = "";
	m.desc = "";
	m.name = name;
	m.wt.timeOpen = "00:00";
	m.wt.timeClose = "00:00";
	m.tags = tags;
	m.inventory = ings;
	
	writeRest(m);

	return 0;
}

user userGet(string username)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	user m;
	if (dbase["USERS"].contains(username))
	{
		m.username = username;
		dbase["USERS"][m.username]["password"].get_to(m.password);
		dbase["USERS"][m.username]["fullName"].get_to(m.fullName);
		dbase["USERS"][m.username]["address"].get_to(m.address);
		dbase["USERS"][m.username]["phone"].get_to(m.phone);
		dbase["USERS"][m.username]["imagePath"].get_to(m.imagePath);
		dbase["USERS"][m.username]["balance"].get_to(m.balance);
		//TODO: dodati order history kad se implementira
	}
	return m;
}

rest restGet(string username)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;
	rest m;
	// TODO: Signalizacija neuspješnosti
	if (dbase["RESTS"].contains(username))
	{
		m.username = username;
		dbase["RESTS"][m.username]["password"].get_to(m.password);
		dbase["RESTS"][m.username]["passwordAd"].get_to(m.passwordAd);
		dbase["RESTS"][m.username]["address"].get_to(m.address);
		dbase["RESTS"][m.username]["imagePath"].get_to(m.imagePath);
		dbase["RESTS"][m.username]["name"].get_to(m.name);
		dbase["RESTS"][m.username]["desc"].get_to(m.desc);
		dbase["RESTS"][m.username]["worktime"]["open"].get_to(m.wt.timeOpen);
		dbase["RESTS"][m.username]["worktime"]["close"].get_to(m.wt.timeClose);
		dbase["RESTS"][m.username]["tags"].get_to(m.tags);
		
		ingr ing;
		for (it i = dbase["RESTS"][m.username]["ingr"].begin(); i != dbase["RESTS"][m.username]["ingr"].end(); i++)
		{
			ing.name = i.key();
			ing.amnt = i.value();
			m.inventory.push_back(ing);
			// TODO: Petar: m.inventory.push_back( {i.key(), i.value()} );
		}
	}
	return m;
}

bool adminAuthentication(string username, string passwordAdPureText)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];

	if (rests.contains(username))
	{
		SHA1 sha;
		sha.update(passwordAdPureText);
		string result = sha.final();

		json password = dbase["RESTS"][username]["passwordAd"];
		if (password == result)
			return true;
	}
	return false;
}

void checkDBase()
{
	ifstream file("dbase.json");
	if (!file.good() || file.peek() == ifstream::traits_type::eof())
	{
		printf("checkDBase: Fajl dbase.json ne postoji, kreiramo ga...\n");
		file.close();
		ofstream file2("dbase.json");
		file2 << "{" << std::endl;
		file2 << "\"idCount\": 0";
		file2 << std::endl;
		file2 << "}";
		file2.close();
	}
	else printf("checkDBase: Fajl dbase.json postoji!\n");
	file.close();

	checkOrdersFile();
	checkOrdersHistFile();

}

void checkOrdersFile()
{
	ifstream file("orders.json");
	if (!file.good() || file.peek() == ifstream::traits_type::eof())
	{
		printf("checkOrdersFile: Fajl orders.json ne postoji, kreiramo ga...\n");
		file.close();
		ofstream file2("orders.json");
		file2 << "{";
		file2 << std::endl;
		file2 << "}";
		file2.close();
	}
	else printf("checkOrdersFile: Fajl orders.json postoji!\n");
	file.close();
}

void checkOrdersHistFile()
{
	ifstream file("ordersHist.json");
	if (!file.good() || file.peek() == ifstream::traits_type::eof())
	{
		printf("checkOrdersFile: Fajl ordersHist.json ne postoji, kreiramo ga...\n");
		file.close();
		ofstream file2("ordersHist.json");
		file2 << "{";
		file2 << std::endl;
		file2 << "}";
		file2.close();
	}
	else printf("checkOrdersFile: Fajl ordersHist.json postoji!\n");
	file.close();
}

int userRemove(string username, string confirmUsername, string passwordPureText)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json users = dbase["USERS"];
	if (users.contains(username))
	{
		SHA1 sha;
		sha.update(passwordPureText);
		string result = sha.final();

		if (username == confirmUsername)
		{
			json password = dbase["USERS"][username]["password"];
			if (password != result)
				return 2;
		}
		else
			return 3;

		users.erase(username);
		if (users.empty())
		{
			dbase.erase("USERS");
		}
		else
		{
			dbase["USERS"] = users;
		}
		file.close();
		ofstream out("dbase.json");
		out << dbase.dump(4);
		out.close();

		return 0;
	}
	return 1;
}

int restRemove(string username, string confirmUsername, string passwordAdPureText)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (rests.contains(username))
	{
		SHA1 sha;
		sha.update(passwordAdPureText);
		string result = sha.final();

		if (username == confirmUsername)
		{
			json password = dbase["RESTS"][username]["passwordAd"];
			if (password != result)
				return 2;
		}
		else
			return 3;

		rests.erase(username);
		if (rests.empty())
		{
			dbase.erase("RESTS");
		}
		else
		{
			dbase["RESTS"] = rests;
		}
		file.close();
		ofstream out("dbase.json");
		out << dbase.dump(4);
		out.close();

		return 0;
	}
	return 1;
}

int userUpdate(string username, string address, string fullName, string passwordPureText, string oldPassword, string phone, string imagePath)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json users = dbase["USERS"];
	if (!users.contains(username))
		return 4;

	SHA1 sha;

	sha.update(oldPassword);
	string result = sha.final();

	if (users[username]["password"] != result)
		return 1;

	if (!imagePath.empty())
		if (ifstream(imagePath).fail())
			return 3;

	if (!std::all_of(phone.begin(), phone.end(), isdigit))
		return 2;

	user temp = userGet(username);

	if (!(imagePath.empty() || imagePath == temp.imagePath))
		temp.imagePath = imagePath;
	if (!(address.empty() || address == temp.address))
		temp.address = address;
	if (!(fullName.empty() || fullName == temp.fullName))
		temp.fullName = fullName;
	if (!(phone.empty() || phone.find(' ') < phone.length() || phone == temp.phone))
		temp.phone = phone;

	sha.update(passwordPureText);
	result = sha.final();

	if (!(passwordPureText.empty() || result == temp.password))
		temp.password = result;

	writeUser(temp);
	return 0;
}

int restUpdate(string username, string address, string desc, string imagePath, string passwordPureText, string passwordAd, string oldPasswordAd, vector<string> tags, workTime wt)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (!rests.contains(username))
		return 2;

	SHA1 sha;

	sha.update(oldPasswordAd);
	string result = sha.final();

	if (rests[username]["passwordAd"] != result)
		return 1;

	if (!imagePath.empty())
		if (ifstream(imagePath).fail())
			return 3;

	unsigned short hrCls, hrOpn, mnCls, mnOpn;
	char colon;

	std::istringstream iss1(wt.timeOpen);
	std::istringstream iss2(wt.timeClose);

	iss1 >> hrOpn >> colon >> mnOpn;
	iss2 >> hrCls >> colon >> mnCls;

	if (!iss1.str().empty() || !iss2.str().empty())
	if (
		hrCls > 24 || hrOpn > 24 || hrCls < 0 || hrOpn < 0
		|| mnCls > 60 || mnOpn > 60 || mnCls < 0 || mnOpn < 0 || colon != ':'
	) return 4;

	rest temp = restGet(username);

	if (!(address.empty() || address == temp.address))
		temp.address = address;
	if (!(desc.empty() || desc == temp.desc))
		temp.desc = desc;
	if (!(imagePath.empty() || imagePath == temp.imagePath))
		temp.imagePath = imagePath;

	if (temp.tags != tags)
		temp.tags = tags;

	if (!(temp.wt.timeClose == wt.timeClose && temp.wt.timeOpen == wt.timeOpen))
		temp.wt = wt;

	sha.update(passwordAd);
	result = sha.final();

	if (!(passwordAd.empty() || result == temp.passwordAd))
		temp.passwordAd = result;

	sha.update(passwordPureText);
	result = sha.final();

	if (!(passwordPureText.empty() || result == temp.password))
		temp.password = result;

	writeRest(temp);
	return 0;
}

int resourceCreate(string username, ingr ingrr) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	// Provjera ako nalog ne postoji
	json rests = dbase["RESTS"];
	if ( !(rests.contains(username) )) return 2;

	// Provjera ako resurs sa datim imenom već postoji
	if ( rests[username]["ingr"].contains(ingrr.name) ) return 1;

	// Dodajemo resurs
	dbRestCurrUser["ingr"][ingrr.name] = ingrr.amnt;

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;

}

int resourceUpdate(string username, string resName, int resAmnt) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];

	if ( !(rests.contains(username)) ) return 1;

	// TODO: Resurs se ažurira tako što se klikne na dugme,
	//       nije moguće da ne postoji

	if ( !(rests[username]["ingr"].contains(resName)) ) return 2;

	// Ažuriramo resurs
	dbRestCurrUser["ingr"][resName] = resAmnt;

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;

}

int resourceDelete(string username, string resourceName) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];

	if (!rests.contains(username)) return 1;

	if (!rests[username]["ingr"].contains(resourceName)) return 2;

	for (it iterr = rests[username]["articles"].begin(); iterr != rests[username]["articles"].end(); ++iterr) {
		if ( (*iterr)["ingredients"].contains(resourceName) ) return 3;
	}

	(dbRestCurrUser["ingr"]).erase((dbRestCurrUser["ingr"]).find(resourceName));

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;

}

int articleCreate(string username, article artt) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (!rests.contains(username)) return 2;

	// Provjera ako artikl sa datim imenom već postoji
	std::transform(artt.name.begin(), artt.name.end(), artt.name.begin(), tolower);

	if ( rests[username]["articles"].contains(artt.name)) return 1;
	if (artt.name.empty()) return 3;
	if (artt.ingredients.size() == 0 || artt.ingredients.empty()) return 4;
	if (artt.tags.empty() || artt.tags.size() == 0) return 5;

	dbase["RESTS"][username]["articles"][artt.name]["price"] = artt.price;
	dbase["RESTS"][username]["articles"][artt.name]["desc"] = artt.desc;
	dbase["RESTS"][username]["articles"][artt.name]["imagePath"] = artt.imagePath;
	dbase["RESTS"][username]["articles"][artt.name]["id"] = dbase["idCount"];

	int idCount = (int)(dbase["idCount"]);
	idCount++;
	dbase["idCount"] = idCount;

	for (int j = 0; j < artt.ingredients.size(); j++) {
		dbRestCurrUser["articles"][artt.name]["ingredients"][artt.ingredients[j].name] = artt.ingredients[j].amnt;
	}

	dbRestCurrUser["articles"][artt.name]["tags"] = artt.tags;

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;
}

int articleUpdate(string username, article artt) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (!rests.contains(username)) return 2;

	// Provjera ako artikl sa datim imenom već postoji
	if ( !rests[username]["articles"].contains(artt.name) ) return 1;

	if (artt.ingredients.empty()) return 3;
	if (artt.tags.empty()) return 4;

	dbase["RESTS"][username]["articles"][artt.name]["price"] = artt.price;
	dbase["RESTS"][username]["articles"][artt.name]["desc"] = artt.desc;
	dbase["RESTS"][username]["articles"][artt.name]["imagePath"] = artt.imagePath;
	//dbase["RESTS"][username]["articles"][artt.name]["id"] = artt.id;

	
	dbRestCurrUser["articles"][artt.name]["ingredients"].clear();

	for (int j = 0; j < artt.ingredients.size(); j++) {
		if (artt.ingredients[j].amnt != 0)
			dbRestCurrUser["articles"][artt.name]["ingredients"][artt.ingredients[j].name] = artt.ingredients[j].amnt;
	}

	dbRestCurrUser["articles"][artt.name]["tags"].clear();

	for (int k = 0; k < artt.tags.size(); k++)
		dbRestCurrUser["articles"][artt.name]["tags"][k] = artt.tags[k];

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;

}

int articleDelete(string username, string articleName) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	json rests = dbase["RESTS"];
	if (!rests.contains(username)) return 2;

	// Provjera ako artikl sa datim imenom već postoji
	if ( !rests[username]["articles"].contains(articleName) ) return 1;

	(dbRestCurrUser["articles"]).erase((dbRestCurrUser["articles"]).find(articleName));

	file.close();
	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	return 0;

}

/*
 * Pravimo pretpostavku da se pristupa iz UI-a, dakle restoran postoji, te to nije problem
 * Takođe pretpostavljamo da svaki artikl iz order.IDarticles postoji
 */

// Luka P: Ja ne znam da li ce ovo raditi.
// Petre, samo pogledaj ovo kasnije kad stignes.
// Nemam trenutno vremena da detaljno prolazim kroz sve.
// Ne zelimo moci naruciti iz vise restorana odjednom, nego
// samo iz jednog.

void orderCreate(order& orderr) {

	ifstream fileOr("orders.json");
	json orders;
	fileOr >> orders; // Read-write

	ifstream fileDB("dbase.json");
	json dbase;
	fileDB >> dbase; // Read-only

	int orderCounter = 0;

	// lastIndex čuva prvi indeks u koji se može pisati narudžba
	int lastId = 0;
	for (auto orderIter : orders) lastId++;
	// TODO: Price bi možda trebao da se izračuna ovde
	string lastIndex = std::to_string(lastId);

	orders[lastIndex]["price"] = orderr.price;
	orders[lastIndex]["comment"] = orderr.comment;
	orders[lastIndex]["time"]["order"] = orderr.timeOrd;
	orders[lastIndex]["time"]["deliver"] = orderr.timeRec;
	orders[lastIndex]["userUName"] = orderr.userUName;
	orders[lastIndex]["restName"] = orderr.restName;
	orders[lastIndex]["processed"] = false;

	// TODO: Petar: Ovo ne treba, ja mislim
	for (int i = 0; i < orderr.IDarticles.size(); i++) {
		orders[lastIndex]["IDarticles"][i] = orderr.IDarticles[i];
	}

	fileOr.close();
	ofstream fileOr1("orders.json");
	fileOr1 << orders.dump(4);
	fileOr1.flush();

}

vector<order> getUnprocessedOrdersForRest(string restName)
{
	ifstream fileOr("orders.json");
	json orders;
	fileOr >> orders;

	vector<order> vecorders;

	int lastIndex = 0;
	for (auto orderIter : orders) lastIndex++;

	order ord;

	for (int i = 0; i < lastIndex; i++)
	{
		ord.userUName = orders[i]["userUName"];
		ord.restName = orders[i]["restName"];
		ord.price = orders[i]["price"];
		ord.processed = orders[i]["processed"];
		ord.comment = orders[i]["comment"];

		ord.timeOrd = orders[lastIndex]["time"]["order"];
		ord.timeRec = orders[lastIndex]["time"]["deliver"];
		orders[lastIndex]["IDarticles"].get_to(ord.IDarticles);

		if ((orders[i]["processed"] == false) && (orders[i]["restName"] == restName))
			vecorders.push_back(ord);
	}

	return vecorders;
}

int processOrder(order& orderr, string accepted , bool& o)
{
	ifstream file("dbase.json");
	json dbase;
	file >> dbase;

	ifstream fileOrH("ordersHist.json");
	json ordersHist;
	fileOrH >> ordersHist;

	ifstream fileOr("orders.json");
	json orders;
	fileOr >> orders;

	if ( orderr.processed ) return 1;

	// order size
	string osz = std::to_string(ordersHist.size());

	// TODO: Dodajemo novu vrijednost u JSON, accepted: <bool>
	ordersHist[osz]["accepted"] = accepted;

	ordersHist[osz]["price"] = orderr.price;
	ordersHist[osz]["comment"] = orderr.comment;
	ordersHist[osz]["time"]["order"] = orderr.timeOrd;
	ordersHist[osz]["time"]["deliver"] = orderr.timeRec;
	ordersHist[osz]["userUName"] = orderr.userUName;
	ordersHist[osz]["restName"] = orderr.restName;
	for (int i = 0; i < orderr.IDarticles.size(); i++) {
		ordersHist[osz]["IDarticles"][i] = orderr.IDarticles[i];
	}

	// Skidanje resursa

	vector<string> articles;
	vector<ingr> ings;
	vector<ingr> newRestIngs;
	if (accepted == "1") {
		for (const auto& id : orderr.IDarticles)
			articles.push_back(getArticleNameFromID(id));

		// j.key() articlename
		for (it j = dbase["RESTS"][orderr.restName]["articles"].begin(); j != dbase["RESTS"][orderr.restName]["articles"].end(); j++)
		{
			// ako postoji artikal u tom restoranu oduzmi ingredients od njega
			for (string name : articles)
			{
				if (name == j.key())
				{
					// k.key() ing name
					// k.value() ing amnt
					for (it k = dbase["RESTS"][orderr.restName]["articles"][j.key()]["ingredients"].begin(); k != dbase["RESTS"][orderr.restName]["articles"][j.key()]["ingredients"].end(); k++)
					{
						ingr in;
						in.name = k.key();
						in.amnt = k.value();
						ings.push_back(in);
					}
				}
			}
			//o.key() ing name
			//o.value() ing amnt
			for (it o = dbase["RESTS"][orderr.restName]["ingr"].begin(); o != dbase["RESTS"][orderr.restName]["ingr"].end(); o++)
			{
				ingr in;
				in.name = o.key();
				in.amnt = o.value();

				for (int i = 0; i < ings.size(); i++)
				{
					ingr ingredient = ings.at(i);
					if (ingredient.name == in.name)
					{
						in.amnt -= ings.at(i).amnt;
						newRestIngs.push_back(in);
					}
				}
			}
		}

		for (int i = 0; i < newRestIngs.size(); i++)
		{
			if (newRestIngs.at(i).amnt > 999999)
				return 2;
		}

		for (int i = 0; i < newRestIngs.size(); i++)
			dbase["RESTS"][orderr.restName]["ingr"][newRestIngs.at(i).name] = newRestIngs.at(i).amnt;

		// Skidanje resursa

		bool makeBox = false;

		for (auto ing : newRestIngs)
			if (ing.amnt < 30)
				makeBox = true;

		if (makeBox == true)
			o = true;
	}

	string ordname = getIDfromOrder(orderr);
	orders.erase(getIDfromOrder(orderr));
	orderr.processed = true;

	orders[ordname]["price"] = orderr.price;
	orders[ordname]["comment"] = orderr.comment;
	orders[ordname]["time"]["order"] = orderr.timeOrd;
	orders[ordname]["time"]["deliver"] = orderr.timeRec;
	orders[ordname]["userUName"] = orderr.userUName;
	orders[ordname]["restName"] = orderr.restName;
	orders[ordname]["processed"] = orderr.processed;

	for (int i = 0; i < orderr.IDarticles.size(); i++) {
		orders[ordname]["IDarticles"][i] = orderr.IDarticles[i];
	}

	fileOrH.close();
	fileOr.close();
	file.close();

	ofstream file1("dbase.json");
	file1 << dbase.dump(4);

	ofstream fileOrH1("ordersHist.json");
	fileOrH1 << ordersHist.dump(4);

	ofstream fileOr1("orders.json");
	fileOr1 << orders.dump(4);

	return 0;

}

//bool checkOrders(string restName, int counter)
//{
//	ifstream fileOr("orders.json");
//	json orders;
//	fileOr >> orders;
//
//	int counter1 = 0;
//
//	for (it i = orders.begin(); i != orders.end(); i++)
//	{
//		if (orders[i.key()]["restName"] == restName && orders[i.key()]["processed"] == false)
//			counter1++;
//	}
//
//	if (counter == counter1)
//		return false;
//	else
//		return true;
//}

int getRestOrders(string restName)
{
	ifstream fileOr("orders.json");
	json orders;
	fileOr >> orders;

	int orderCount = 0;

	for (it i = orders.begin(); i != orders.end(); i++)
	{
		if (orders[i.key()]["restName"] == restName && orders[i.key()]["processed"] == false)
			orderCount++;
	}

	return orderCount;
}

bool validCard(string clean_number)
{
	std::reverse(clean_number.begin(), clean_number.end());

	int sum = 0;

	for (size_t i = 0; i < clean_number.length(); ++i)
	{
		int digit = clean_number[i] - '0';

		if (i % 2 == 1)
		{
			digit *= 2;

			if (digit > 9)
				digit -= 9;
		}
		sum += digit;
	}
	return (sum % 10 == 0);
}

int addMoney(string username, string cardNumber, string expMonth, string expYear, double money)
{
	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	if (!validCard(cardNumber))
		return 1;
	if (stoi(expMonth) == 1 || stoi(expMonth) == 0 || stoi(expYear) < 2024)
		return 2;
	
	user temp = userGet(username);

	double oldmoney = dbase["USERS"][username]["balance"];
	double newmoney = money + oldmoney;

	temp.balance = newmoney;

	writeUser(temp);
	return 0;
}

vector<rest> searchForRests(string searchWord)
{
	vector<rest> rests = parseRestsFromDBase();
	vector<rest> restsReturn;
	
	for (int i = 0; i < rests.size(); i++)
	{
		if ((rests.at(i).name.find(searchWord) != string::npos))
			restsReturn.push_back(rests.at(i));
	}

	return restsReturn;
}

string receipt(order orderr) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	//if (!orderr.processed || orderr.IDarticles.empty()) return "";

	time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	stringstream receipt;

	receipt << "=============================="<< endl;
	receipt << endl;
	receipt << "             FFDM             "<< endl;
	receipt << "        FISKALNI RACUN        "<< endl;
	receipt << endl;
	receipt << "=============================="<< endl;
	receipt << endl;
    receipt << std::put_time(std::localtime(&now), "%H:%M:%S %d/%m/%Y") << std::endl;
	receipt << endl;
	receipt << "=============================="<< endl;
	receipt << endl;
	receipt << "VRIJEME SLANJA:       " << orderr.timeOrd << endl;
	receipt << "VRIJEME DOSTAVLJANJA: " << orderr.timeRec << endl;
	receipt << "RESTORAN: " << orderr.restName << endl;
	receipt << endl;

	std::unordered_map<std::string, int> articleCount;

	for (size_t i = 0; i < orderr.IDarticles.size(); ++i) {
		const std::string& articleName = orderr.artNames[i];
		articleCount[articleName]++;
	}

	int iReceipt = 0;

	for (unordered_map<string, int>::iterator it = articleCount.begin(); it != articleCount.end(); ++it) {

		float singlePrice = dbase["RESTS"][orderr.restName]["articles"][orderr.artNames[iReceipt]]["price"];

		receipt <<
			std::to_string(iReceipt+1) << ": " << it->first << " x" << it->second <<
			endl <<
			"  " << static_cast<float>(it->second) * singlePrice << " KM" <<
			endl;

		iReceipt++;

	}

	receipt << endl << "TOTAL: " << orderr.price << "KM" << endl;

	receipt << endl << "==============================" << endl;
	receipt         << "      PDV NIJE URACUNAT!      "; // TODO: Petar: hehe
	receipt << endl << "==============================";

	return receipt.str();

}

vector<order> ordersJSONuOrdersVec() {

	ifstream file("orders.json");
	json jsonData;
	file >> jsonData;

	vector<order> orders;

	for (auto& entry : jsonData.items()) {
		order newOrder;

		json orderData = entry.value();

		newOrder.price = orderData["price"];
		newOrder.comment = orderData["comment"];
		newOrder.timeOrd = orderData["time"]["order"];
		newOrder.timeRec = orderData["time"]["deliver"];
		newOrder.userUName = orderData["userUName"];
		newOrder.processed = orderData["processed"];
		newOrder.restName = orderData["restName"];

		for (auto& id : orderData["IDarticles"]) {
			newOrder.IDarticles.push_back(id);
		}

		for (auto& artName : orderData["artNames"]) {
			newOrder.artNames.push_back(artName);
		}

		orders.push_back(newOrder);
	}

	return orders;

}

string getIDfromOrder(order ord)
{
	ifstream file("orders.json");
	json jsonData;
	file >> jsonData;
	string id = "";
	for (it i = jsonData.begin(); i != jsonData.end(); i++)
	{
		if (jsonData[i.key()]["comment"] == ord.comment)
		if (jsonData[i.key()]["userUName"] == ord.userUName)
		if (jsonData[i.key()]["time"]["order"] == ord.timeOrd)
		if (jsonData[i.key()]["time"]["deliver"] == ord.timeRec)
		if (jsonData[i.key()]["restName"] == ord.restName)
		if (jsonData[i.key()]["price"] == ord.price)
		if (jsonData[i.key()]["IDarticles"] == ord.IDarticles)
		{
			id = i.key();
			if (id != "")
			return id;
		}
	}
	return "";
}

order getOrderFromID(string id)
{
	ifstream file("orders.json");
	json jsonData;
	file >> jsonData;

	order ord;

	jsonData[id]["processed"].get_to(ord.processed);
	jsonData[id]["comment"].get_to(ord.comment);
	jsonData[id]["userUName"].get_to(ord.userUName);
	jsonData[id]["time"]["order"].get_to(ord.timeOrd);
	jsonData[id]["time"]["deliver"].get_to(ord.timeRec);
	jsonData[id]["restName"].get_to(ord.restName);
	jsonData[id]["price"].get_to(ord.price);
	jsonData[id]["IDarticles"].get_to(ord.IDarticles);

	return ord;
}

// PRETPOSTAVLJAMO DA KORISNIK POSTOJI
bool userSubtractBalance( string username, double amnt ) {

	ifstream file("dbase.json");

	json dbase;
	file >> dbase;

	double bal = dbase["USERS"][username]["balance"];

	if ( bal < amnt ) return false;

	dbase["USERS"][username]["balance"] = bal - amnt;

	file.close();

	ofstream out("dbase.json");
	out << dbase.dump(4);
	out.close();

	return true;

}

stats getRestStats( string username ) {

	json  tmpJson;
	stats ret;

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

vector<order> getOrderHistVector( string username ) {

	order tmpOrder;
	json  tmpJson;

	vector<order> ret;

	ifstream file("ordersHist.json");

	json orders;
	file >> orders;

	int i = 0;
	while ( orders[ to_string(i) ] != nullptr ) {
		
		tmpOrder.artNames.clear();
		tmpOrder.IDarticles.clear();
		tmpJson = orders[to_string(i)];

		if (tmpJson["userUName"] == username) {

			tmpOrder.price = tmpJson["price"];
			tmpOrder.restName = tmpJson["restName"];
			tmpOrder.comment = tmpJson["comment"];
			tmpOrder.timeOrd = tmpJson["time"]["order"];
			tmpOrder.timeRec = tmpJson["time"]["deliver"];

			for (int j = 0; tmpJson["IDarticles"][j] != nullptr; j++) {

				tmpOrder.artNames.push_back(
					getArticleNameFromID( tmpJson["IDarticles"][j] )
				);

				tmpOrder.IDarticles.push_back(
					tmpJson["IDarticles"][j]
				);

			}

			// Petar: Ovo je hack koji koristimo da znamo da li je narudžba
			// bila procesuirana

			string acc;
			tmpJson["accepted"].get_to(acc);
			tmpOrder.processed = (bool)stoi(acc);
			
			ret.push_back(tmpOrder);

		}

		i++;

	}

	return ret;

}

string getRestName(string username)
{
	ifstream fileDB("dbase.json");
	json dbase;
	fileDB >> dbase;

	string restName = "";
	restName = dbase["RESTS"][username]["name"];

	return restName;
}