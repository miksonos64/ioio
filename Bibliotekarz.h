#ifndef BIBLIOTEKARZ_H
#define BIBLIOTEKARZ_H
#include "Ksiazka.h"
#include<iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

class Bibliotekarz
{
	public:
		string name;
		vector<Ksiazka>tab_rezerwacji;
		Bibliotekarz(string x);
		~Bibliotekarz();
	protected:
};

#endif
