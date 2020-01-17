#include <iostream>
#include "KartaCzytelnika.h"
#include "Czytelnik.h"
#include "Autor.h"
#include "Ksiazka.h"
#include "Bibliotekarz.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include<bits/stdc++.h>
#include <iomanip>




using namespace std;

int loguj();
void rejestruj();
void wypisz(string a, string b );

vector<pair <Ksiazka, int> > tab_egzemplarz;
Czytelnik *c2;
Bibliotekarz  *b2;

string tytul;

int loguj()

 {

	fstream plik;

	string line1;

	string line2;

	string line3;

	string line4;

	string IDKarty1;

	string haslo;

	cout<<"Podaj login: ";	cin>>IDKarty1;

	cout<<"Podaj haslo: ";	cin>>haslo;

	cout<<endl;

	plik.open("data.txt", ios::in | ios::out);

	if (plik.good()==true)

	{

		while(!plik.eof())

		{

			plik>>line1;

			plik>>line2;

			plik>>line3;

			plik>>line4;

		if(IDKarty1==line3 && haslo==line4){
		
			Czytelnik c1(line4, line3, line1, line2);
			
			c2=&c1;



			//cout<<"witaj "<< line1 <<" "<< line2<<endl;

			wypisz(line1, line2);

			return 1;

			//goto a;

		}

		else{

		

		//cout<<"blad";

		

		

			}

		}

		//a:

	plik.close();

	cout<<"nie ma takiego id lub hasla"<<endl<<endl;

	return 2;

	}

}


void dostepnosc(){
	cout<<endl;
	cout<<endl;
	cout<<setw(8)<<"LISTA DOSTEPNYCH KSIAZEK"<<endl;
	for(int i=0; i<tab_egzemplarz.size();i++){
		 cout<<" * "<<tab_egzemplarz[i].first.tytul<<" * "<<setw(10);
		 tab_egzemplarz[i].first.wypisz_autorow_ksiazki();
		 cout<<setw(4)<<tab_egzemplarz[i].second<<endl;
	}
	
	cout<<endl;
	cout<<endl;
}

void wypozycz(string tytul, Czytelnik *c2)
{
	
	for(int i=0; i<tab_egzemplarz.size();i++)
	{
		
		if(tytul==tab_egzemplarz[i].first.tytul && tab_egzemplarz[i].second>0){
		
			c2->ksiazki_czytelnika.push_back(tab_egzemplarz[i].first);
			tab_egzemplarz[i].second--;
			
		
		}

	}
	
	cout<<"wypozyczona"<<endl;
}

void rezerwuj(string tytul, Bibliotekarz *b1,Czytelnik *c2)
{
	
	for(int i=0; i<tab_egzemplarz.size();i++)
	{
		
		if(tytul==tab_egzemplarz[i].first.tytul && tab_egzemplarz[i].second==0){
			b1->tab_rezerwacji.push_back(tab_egzemplarz[i].first);
			cout<<"Zarezerwowana"<<endl;
		
			
		
		}
			else if(tytul==tab_egzemplarz[i].first.tytul && tab_egzemplarz[i].second>0)
		cout<<"Ksiazka dostepna mozesz ja wypozyczyc "<<endl;
		
			else if(tytul!=tab_egzemplarz[i].first.tytul && tab_egzemplarz[i].second==0)
		cout<<"Zly tytul"<<endl;
	}
	

}

void wypisz_zarezerwowane(Bibliotekarz *b1, Czytelnik *c2){
	cout<<endl;
	cout<<endl;
	cout<<setw(8)<<"LISTA ZAREZERWOWANYCH KSIAZEK"<<endl;
	for(int i=0; i<b1->tab_rezerwacji.size();i++){
		 cout<<" # "<<b1->tab_rezerwacji[i].tytul<<" # "<<setw(4);
		 b1->tab_rezerwacji[i].wypisz_autorow_ksiazki();
		 
	}
	
	cout<<endl;
	cout<<endl;
}

void dodaj_ksiazke(){
	int n;
	
	cout<<"Ile dodajemy ksiazek"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	string tyt;
	string im;
	string naz;
	int egz;
	cout<<"Podaj tytul "<<i+1<<" ksiazki"<<endl;
	cin>>tyt;
	cout<<"Podaj imie "<<i+1<<" autora"<<endl;
	cin>>im;
	cout<<"Podaj nazwisko "<<i+1<<" nazwisko"<<endl;
	cin>>naz;
	cout<<"Ile egzemplarzy:"<<endl;
	cin>>egz;
	Ksiazka z$i(tyt);
	Autor g$i(im,naz);
	z$i.przypisz_autora(g$i);
	g$i.przypisz_ksiazke(z$i);
	tab_egzemplarz.push_back( make_pair(z$i,egz) ); 
		
	}
	
	
	
	
	
	
}

int main() {
	Bibliotekarz b1("BIBLIO");
	b2=&b1;
	
	Autor a1("Adam", "Mickiewicz");
	Autor a2("Juliusz", "Slowacki");
	Autor a3("Boleslaw", "Prus");
	Autor a4("Stanis³aw", "Zeromski");
	
	Ksiazka k1("Dziady");
	k1.przypisz_autora(a1);
	
	Ksiazka k2("Pan Tadeusz");
	k2.przypisz_autora(a1);
	
	Ksiazka k3("Konrad Wallendrod");
	k3.przypisz_autora(a2);
	Ksiazka k4("Kordian");
	k4.przypisz_autora(a2);
	Ksiazka k5("Przedwiosnie");
	k5.przypisz_autora(a4);
	Ksiazka k6("Lalka");
	k6.przypisz_autora(a3);
	Ksiazka arr[] = {k1,k2,k3,k4,k5,k6};
	int arr1[] = {0,6,2,8,4,9};
	int n = sizeof(arr)/sizeof(arr[0]); 
	for (int i=0; i<n; i++) 
        tab_egzemplarz.push_back( make_pair(arr[i],arr1[i]) ); 
  

start:
	cout<<"|----------------------------------|"<<endl;
	cout<<"|  Witaj w systemie bibliotecznym  |"<<endl;
	cout<<"|----------------------------------|"<<endl<<endl;

	cout<<" 1. Zarejestruj sie "<<endl;

	cout<<" 2. Zaloguj sie "<<endl;
	
	cout<< " 3. KONIEC "<<endl<<endl;

	int wybor;
	
	cin>>wybor;
	cout<<endl;

	

	switch(wybor)

	{

		case 1:

			rejestruj();

			cout<<endl;

			goto start;

			break;

		case 2:

			// loguj();
			if(loguj()==1)
			goto inter1;
			else
			goto start;

			break;
		
		case 3:

			cout<<"DZIEKUJEMY";
			return 0;

			break;

		case 0:

			//admin();

			goto interad;

			break;

	}

	

inter1:

	
	cout<<"|----------------------------------|"<<endl;
	cout<<"|         Panel czytelnika         |"<<endl;
	cout<<"|----------------------------------|"<<endl<<endl;

	cout<<" 1. Sprawdz dostepnosc "<<endl;

	cout<<" 2. Wypozycz ksiazke "<<endl;

	cout<<" 3. Zarezerwuj ksiazke "<<endl<<endl;

	//cout<<" 3. Oddaj ksiazke "<<endl;

	

	int wybor1;

	cin>>wybor1;

	

	switch(wybor1)

	{

		case 1:

			
			
			dostepnosc();
			goto inter1;
			cout<<endl;

			break;

		case 2:

				cout<<"Podaj tytul:"<<endl;
				cin>>tytul;
				wypozycz(tytul,c2);
				goto inter1;
			

			break;

		case 3:
			
			cout<<"Podaj tytul ksiazki jaka chcesz zarezerwowac:"<<endl;
			cin>>tytul;
			rezerwuj(tytul, b2, c2);
			goto start;
			break;
		case 0:

			//admin();

			break;

	}

	

interad:
	cout<<"|----------------------------------|"<<endl;
	cout<<"|        Panel bibliotekarza       |"<<endl;
	cout<<"|----------------------------------|"<<endl<<endl;		
	cout<<" 1. Dodaj ksiazke "<<endl;

	cout<<" 2. Wypisz zarezerwowane "<<endl;
	
	cout<<" 3. Cofnij "<<endl<<endl;
	
	int wybor2;

	cin>>wybor2;

	

	switch(wybor2)

	{

		case 1:

			
			
			dodaj_ksiazke();
			goto interad;
			cout<<endl;

			break;

		case 2:

				wypisz_zarezerwowane(b2,c2);
				goto interad;
			

			break;

		case 3:
			
			goto start;
			break;
		case 0:

			//admin();

			break;

	}
	

	koniec:

		

	

	//Czytelnik c1("123","123","kamil", "kamil");

	return 0;

}

void rejestruj()

{

	fstream dane;

	string imie;

    string nazwisko;

    string haslo;

	string IDKarty;



	cout<<"Podaj imie:";		cin>>imie;	

	cout<<"Podaj nazwisko:";	cin>>nazwisko;	

	cout<<"Podaj IDKarty:";		cin>>IDKarty;

	cout<<"Podaj haslo:";		cin>>haslo;

	dane.open("data.txt", ios::app);

   //	dane.open("dane.txt",ios::out | ios::app);





		

	dane<<imie<<" ";

		

	dane<<nazwisko<<" ";

			

	dane<<IDKarty<<" ";

	

	dane<<haslo<<" \n";

	

	dane.close();

}






void wypisz(string a, string b ){

	cout<<"Witaj "<<a<<" "<<b<<endl<<endl;

}
