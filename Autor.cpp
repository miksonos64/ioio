#include "Autor.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Ksiazka;

Autor::Autor(string a,string b){
	this->imie = a;
	this->nazwisko = b;
	
}

void::Autor::przypisz_ksiazke(Ksiazka ksiazka) {
	tab_ksiazek.push_back(ksiazka);
};


void::Autor::usun_ksiazke(Ksiazka ksiazka) {
	
	for(int i=0; i<tab_ksiazek.size(); i++){
		if(ksiazka.tytul==tab_ksiazek[i].tytul){
			tab_ksiazek.erase(tab_ksiazek.begin()+i);
			
		}
		
	}
		
	cout <<endl;
};


void::Autor::wypisz_ksiazke_danego_autora() {

	for (int i = 0; i < tab_ksiazek.size(); i++) {
		cout << this->tab_ksiazek[i].tytul<<endl;
	}
	


};




Autor::~Autor()
{
}



