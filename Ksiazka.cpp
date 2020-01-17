#include "Ksiazka.h"
#include <iostream>
#include <string>
using namespace std;


Ksiazka::Ksiazka(string t)
{
	this->tytul=t;
};

void::Ksiazka::przypisz_autora(Autor autor) {
	tab_autorow.push_back(autor);
};


void::Ksiazka::usun_autora(Autor autor) {
	
	for(int i=0; i<tab_autorow.size(); i++){
		if(autor.imie==tab_autorow[i].imie && autor.nazwisko==tab_autorow[i].nazwisko){
			tab_autorow.erase(tab_autorow.begin()+i);
			
		}
		
	}
		
	cout <<endl;
};


void::Ksiazka::wypisz_autorow_ksiazki() {

	for (int i = 0; i < tab_autorow.size(); i++) {
		cout << this->tab_autorow[i].imie<<"  ";
		cout << this->tab_autorow[i].nazwisko;
	}
	


};



Ksiazka::~Ksiazka(){
};


