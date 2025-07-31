#pragma once
#include "datatypes.h"
#include "nlohmann/json.hpp"
#include "sha1.h"
#include <fstream>

using json = nlohmann::json;
using std::ifstream;
using std::ofstream;
using it = json::iterator;

vector<string> getPeroArtikliIme();
vector<int> getPeroArtikliPuta();

void peroArtikliConvertOrderToVec(order orderr);

// Dobavlja sve narudžbe iz orders.json u vektor narudžbi
vector<order> ordersJSONuOrdersVec();

vector<string> getArticleTags();

string getProfileImagePath();

void setProfileImagePath(string arg);

bool getAuth();

void setAuth(bool arg);

string getActiveUser();

void setActiveUser(string arg);

string getArticleNameFromID(unsigned int id);

// Pravi 'json' podatak od 'user' podatka
void userToJson(json& j, const user& m);

// Pravi 'json' podatak od 'rest' podatka
void restToJson(json& j, const rest& m);

// Upisuje podatke o user-u u json file na osnovu usernamea
void writeUser(const user& userr);

// Upisuje podatke o restoranu u json file na osnovu usernamea
void writeRest(const rest& restt);

vector<uiid> parseArticleIDsFromRest(string username);

// Ucitava korisnike u niz/vektor
vector<user> parseUsersFromDBase();

// Ucitava restorane u niz/vektor
vector<rest> parseRestsFromDBase();

vector<article> parseArticlesFromRest(string username);

vector<article> parseArticlesFromRestSpecial(string username);

// Vrsi login korisnika
// Return kodovi:
// 0 - uspjesno
// 1 - racun ne postoji
// 2 - lozinka nije tacna
int userLogin(string username, string passwordPureText);

// Vrsi login radnika restorana
// Return kodovi:
// 0 - uspjesno
// 1 - racun ne postoji
// 2 - lozinka nije tacna
int restLogin(string username, string passwordPureText);

// Vrsi registraciju korisnika
// Return kodovi:
// 0 - uspjesno
// 1 - racun vec postoji
// 2 - lozinke se ne poklapaju
int userRegister(string username, string passwordPureText, string confirmPassword, string phone, string fullName, string address);

// Vrsi registraciju korisnika i sacuvava ga u dbase.json
// Return kodovi:
// 0 - uspjesno
// 1 - racun vec postoji
// 2 - lozinke se ne poklapaju
int restRegister(string username, string passwordPureText, string confirmPassword, string passwordAdPureText, string name, string address);

// Ucitava korisnika iz dbase.json fajla prema usernameu
user userGet(string username);

// Ucitava restoran iz dbase.json fajla prema usernameu
rest restGet(string username);

// Vrsi brisanje korisnickog naloga
// Return kodovi
// 0 - uspjesno
// 1 - korisnik ne postoji (sanity-check)
// 2 - lozinka nije tacna
// 3 - username tokom potvrde se ne poklapa sa username-om racuna koji brise profil
//
// username se proslijedi kao username ulogovan korisnika,
// confirmUsername i passwordPureText predstavlja "pseudo-login"
// za konfirmaciju brisanja i za zastitu od zloupotrebe
int userRemove(string username, string confirmUsername, string passwordPureText);

// Vrsi brisanje restoranskog naloga
// Return kodovi:
// 0 - uspjesno
// 1 - korisnik ne postoji (sanity-check)
// 2 - administratorska lozinka nije tacna
// 3 - username tokom potvrde se ne poklapa sa username-om racuna koji brise profil
// isto vazi i ovdje za confirmUsername, kao za userRemove
int restRemove(string username, string confirmUsername, string passwordPureText);	

// Provjeravanje da li je administratorska lozinka tacna
bool adminAuthentication(string username, string passwordPureText);

// Pregledamo da li postoji dbase.json
// ili da li da pravimo novi sa odgovarajucim formatom
void checkDBase();

// Pregledamo da li postoji orders.json
// ili da li da pravimo novi sa odgovarajucim formatom
void checkOrdersFile();

// Pregledamo da li postoji ordersHist.json
// ili da li da pravimo novi sa odgovarajucim formatom
void checkOrdersHistFile();



/* ======== USER I REST UPDATE ======== */



// Funkcija za azuriranje/izmjene podesavanja korisnickog racuna
// Return kodovi:
// 0 - uspjesno
// 1 - pogresna potvrda lozinke
// 2 - broj neispravan
// 3 - imagepath neispravan
// 4 - korisnik ne postoji
int userUpdate(string username, string address, string fullName, string passwordPureText, string oldPassword, string phone, string imagePath);

// Funkcija za azuriranje/izmjene podesavanja restoranskog racuna
// Return kodovi:
// 0 - uspjesno
// 1 - pogresna potvrda administratorske lozinke
// 2 - restoran ne postoji
// 3 - imagepath neispravan
// 4 - radni sati neispravni
int restUpdate(string username, string address, string desc, string imagePath, string passwordPureText, string passwordAd, string oldPasswordAd, vector<string> tags, workTime wt);



/* ========= RESURSI / SASTOJCI ========= */



// Funkcija za kreiranje resursa, koji se potom dodaju na restoranski nalog
// Naopomena:
//   Nisam stavio mogućnost navođenja količine resursa, sve je stavljeno na default vrijednost
// Povratne vrijednosti su:
//   0 - Resurs uspješno dodat
//   1 - Resurs već postoji u restoranskom nalogu
//   2 - Nalog ne postoji
int resourceCreate(string username, ingr ingrr);

// Funkcija za ažurirsanje resursa koji je na nekom restoranskom nalogu
// Povratne vrijednosti su:
//   0 - Resurs uspješno ažuriran
//   1 - Nalog ne postoji
//   2 - Resurs ne postoji
int resourceUpdate(string username, string resName, int resAmnt);

// Funkcija za uklanjanje resursa koji je na nekom restoranskom nalogu
// Povratne vrijednosti su:
//   0 - Resurs uspješno uklonjen
//   1 - Nalog ne postoji
//   2 - Resurs ne postoji
//   3 - Resurs je korišten u nekom artiklu
int resourceDelete(string username, string resourceName);



/* ============== ARTIKLI ============== */



// Funkcija koja kreira artikl
// Povratne vrijednosti su:
//   0 - Artikl uspješno dodat
//   1 - Artikl već postoji u restoranskom nalogu
//   2 - Nalog ne postoji
//   3 - Artikal nema ime
//   4 - Nema sastojaka
//   5 - Nema tagova
int articleCreate(string username, article artt);

// Funkcija za ažurirsanje artikla koji je na nekom restoranskom nalogu
// Povratne vrijednosti su:
//   0 - Artikl uspješno ažuriran
//   1 - Artikl ne postoji
//   2 - Nalog ne postoji
//   3 - Artikal nema sastojke
//   4 - Artikal nema tagove
int articleUpdate(string username, article artt);

// Funkcija za uklanjanje artikla koji je na nekom restoranskom nalogu
// Povratne vrijednosti su:
//   0 - Artikl uspješno uklonjen
//   1 - Artikl ne postoji
//   2 - Nalog ne postoji
int articleDelete(string username, string articleName);



/* ============== NARUDZBE ============== */



// Za restoransku aplikaciju,
// restoran kreira narudžbu, koja se dodaje u
// "orders.json"
void orderCreate(order& orderr);

// Provjerava da li postoji nova narudzba za restoran
//bool checkOrders(string restName, int counter);

// Vraca kolicinu narudzbi za odredjeni restoran
int getRestOrders(string restName);

// Vraca vektor svih narudzbi koje nisu obradjene
vector<order> getUnprocessedOrdersForRest(string restName);

// Omogucava radniku restorana da prihvati i odbije narudzbu
// Odbijanje se radi preko UI-a
//
// Return kodovi:
// 0 - Uspjeno obradjena narudzba
// 1 - Narudzba je vec obradjena
// 2 - Nema dovoljno resursa
int processOrder(order& orderr, string accepted, bool& o);

// Ispituje da li je broj kartice ispravan
bool validCard(string clean_number);

// Omogucava dodavanje novca na racun korisnika
// Return kodovi:
// 0 - uspjesno dodan novac
// 1 - broj kartice nije validan
// 2 - datum isteka nije validan
int addMoney(string username, string cardNumber, string expMonth, string expYear, double money);

// Vraća račun za neku narudžbu
// String je prazan ako:
//   - nema artikala u narudžbi
//   - narudžba nije obrađena
string receipt(order orderr);



/* ============== PRETRAGA ============== */



vector<rest> searchForRests(string searchWord);
string getIDfromOrder(order ord);

order getOrderFromID(string id);


/* ============= STATISTIKA ============= */

// Ulazi u ordersHist.json,
// nalazi sve narudžbe iz jednog restorana,
// smješta ih u stats
stats getRestStats( string username );

// Skida sa računa
// Povratne vrijednosti:
// true  - Uspješno skidanje
// false - Nema toliko novca
bool userSubtractBalance(string username, double amnt);

// Vraća vektor svih narudžbi koje je korisnik napravio
// username mora biti validno korisničko ime korisnika
vector<order> getOrderHistVector( string username );

string getRestName(string username);