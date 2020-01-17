#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <string>
#include <iostream>
#include <vector>
#include "Autor.h"

using namespace std;

class Autor;


class Ksiazka{
public:
	string tytul;
	void usun_egzemplarz();
	Ksiazka zwroc_wolny_egzemplarz();
	Ksiazka(string t);
	vector<Autor>tab_autorow;
	void przypisz_autora(Autor autor );
	void usun_autora(Autor autor);
	void wypisz_autorow_ksiazki();

//	static int il_ksiazek;

	
	
	~Ksiazka();
};

#endif
