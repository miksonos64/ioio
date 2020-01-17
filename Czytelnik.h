#ifndef CZYTELNIK_H
#define CZYTELNIK_H
#include <vector>
#include <cstring>
#include <fstream>
#include "Ksiazka.h"

using namespace std;



class Czytelnik
{	
	

	public:
		string imie;
		string nazwisko;
		string IDkarty;
		string haslo;
		vector<Ksiazka>ksiazki_czytelnika;
		
	
	

		

		Czytelnik(string k,string h, string i, string n);
		~Czytelnik();
	protected:
};

#endif
