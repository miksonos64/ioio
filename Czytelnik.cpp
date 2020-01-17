#include "Czytelnik.h"
#include<iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Ksiazka;
Czytelnik::Czytelnik(string karta , string h, string i, string n):IDkarty(karta), haslo(h) ,imie(i), nazwisko(n)
{
}

	
Czytelnik::~Czytelnik()
{
}


