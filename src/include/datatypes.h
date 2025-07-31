#ifndef FASTFOOD_DATATYPES_H
#define FASTFOOD_DATATYPES_H

/* C++ biblioteke */
#include <string>
#include <vector>
#include <map>

/* C biblioteke */
#include <time.h>

/* Direktive za uvođenje metoda iz STL-a */
using std::string;
using std::vector;
using std::map;

/* Neoznačeni cijeli broj, korišten za identifikacione brojeve */
typedef unsigned int uiid;

/* Pomoćna struktura za radno vrijeme restorana */
typedef struct _workTime {

	string timeOpen, timeClose;

} workTime;

/*
 * Tip podatka koji opisuje jednu narudžbu
 */
typedef struct _order {

	double         price;      /* Cijena ukupne narudžbe */
	string         comment;    /* Komentar koji se dostavlja uz narudžbu */
	string         timeOrd;    /* Vrijeme kada je narudžba napravljena */
	string         timeRec;    /* Vrijeme kada će narudžba biti dostavljena */
	string         userUName;  /* Korisničko ime korisnika koji je podnio narudžbu */

	vector<uiid>   IDarticles; /* Lista ID-eva artikala koje je korisnik naručio */

	string         restName;  /* Imena restorana iz kojih su predmeti narudžbe */
	vector<string> artNames;  /* Imena artikala iz kojih su predmeti narudžbe */
	bool           processed; /* Pokazuje da li je obradjena narudzba (prihvacena/odbijena)*/

} order;

/*
 * Tip podatka koji opisuje korisnika
 * Korišten za kupce koji kupuju hranu od vlasnika
 */
typedef struct _user {

	double        balance;    /* Bankovno stanje */
	string        address;    /* Kućna adresa */
	string        fullName;   /* Puno ime */
	string        imagePath;  /* Put do slike koja je priložena uz artikl */
	string        password;   /* Šifra, enkriptovana koristeći SHA256 */
	string        phone;      /* Broj telefona korisnika */
	string        username;   /* Korisničko ime */
	vector<order> orderHist;  /* Dinamički alocirana lista, sve narudžbe koje je korisnik napravio */

} user;

/*
 * Tip podatka koji opisuje sastojak dostupan u restoranu
 */
typedef struct _ingr {

	string       name; /* Ime sastojka */
	unsigned int amnt; /* Količina dostupna u restoranu */

} ingr;

/*
 * Tip podatka koji opisuje jedan artikl dostupan u restoranu
 */
typedef struct _article {

	double         price;       /* Cijena artikla */
	string         desc;        /* Opis atikla */
	string         imagePath;   /* Put do slike koja je priložena uz artikl */
	string         name;        /* Ime artikla */
	uiid           id;          /* ID artikla */
	vector<ingr>   ingredients; /* Sastojci koji su korišteni u artiklu */
	vector<string> tags;        /* Tag-ovi koji se vezuju za artikl */

} article;

/*
 * Tip podatka koji opisuje restoran
 */
typedef struct _rest {
	string       address;    /* Adresa na kojoj je restoran */
	string       desc;       /* Opis restorana */
	string       imagePath;  /* Put do slike koje je priložena uz restoran */
	string       name;       /* Ime restorana */
	string       password;   /* Šifra naloga odgovornog za restoran, enkriptovana koristeći SHA256 */
	string       passwordAd; /* Administratorska šifra */
	string       username;   /* Koriničko ime naloga odgovornog za restoran */
	vector<ingr> inventory;  /* Inventar, dat kao dinamička lista sastojaka */
	vector<string>  tags;    /* Tag-ovi asocirani sa restoranom */
	// Nepotrebno
	// vector<uiid> IDarticles; /* ID-evi artikala koji su dostupni u restoranu */
	workTime     wt;         /* Radno vrijeme restorana */

} rest;

/*
 * Statistika vezana za jedan restoran
 *
 * Sadrži svaki artikl i koliko puta je naručen
 */
typedef map<string, unsigned int> stats;

#endif
