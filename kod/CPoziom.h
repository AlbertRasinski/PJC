#pragma once
#include <fstream>
#include <vector>

#include "CPokoj.h"

/// klasa CPoziom, pozwala na utworzenie calej planszy, po ktorej porusza sie postac gracza

class CPoziom
{
private:
	/// statyczna stala liczbaPrzedmiotow okresla liczbe przedmiotow, ktore zostaly przygotowane
	static const int liczbaPrzedmiotow;
	/// metoda sprawdzPoprawnoscGenerowania(), ktora pozwala sprawdzic, czy wegenerowany przez nas poziom generujPoziom() jest poprawny (min 2 pokoje, ktore maja tylko 1 sasiedni pokoj), przypisuje odpowiednim pokojom czy zawieraja bossa/treasure
	bool sprawdzPoprawnoscGenerowania();

public:
	/// atrybut okreslajacy ile jest pokoi na danym poziomie
	int liczbaPokoi;
	/// atrybut rodzajPrzedmiotu okresla jaki rodzaj przedmiotu znajduje sie w treasure room
	int rodzajPrzedmiotu;

	/// tablica 2D CPokoj, okresla ktory pokoj jest jakiego rodzaju i co zawieta
	CPokoj poziom[15][15];

	/*!
	\brief kontruktor klasy CPoziom(), inicjalizacja atrybutow
	*/
	CPoziom();

	/*!
	\brief metoda generujPoziom(), tworzy rozklad pokoi na poziomie
	*/
	void generujPoziom();
	/*!
	\brief metoda wczytajPoziom(), jej zadaniem jest otworzenie plikow z danymi oraz na podstawie wygenerowanego wczesniej rozkladu pokoi (generujPoziom()) w odpowiednich pokojach generuje elementy otoczenie/przeciwnikow/bossa/treasure
	*/
	void wczytajPoziom();
};

