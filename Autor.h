#ifndef AUTOR_H
#define AUTOR_H
#include "Ksiazka.h"
#include <iostream>
#include <vector>
#include <bits/stl_vector.h>
#include <algorithm>

using namespace std;
class  Ksiazka;

class Autor{

public:
	string imie;
	//Ksiazka * tablica = new int[Ksiazka.il_ksiazek];
	string nazwisko;
	vector<Ksiazka>tab_ksiazek;
	void przypisz_ksiazke(Ksiazka ksiazka);
	void usun_ksiazke(Ksiazka ksiazka);
	void wypisz_ksiazke_danego_autora();


	Autor(string a, string b);
	~Autor();
};

#endif
