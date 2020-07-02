#pragma once
#include "CPostacGracza.h"
#include "CPociski.h"
#include "CPoziom.h"

#include <fstream>

/// klasa CGra laczy ze soba pozostale klasy ( CPostacGracza CPoziom CPociski ) i wspolnie tworza obiekt, ktory  oblicza przebieg gry 

class CGra
{
private:
	/// statyczna stala stalaPredkoscPociskow sluzy do odliczenia z jaka predkoscia poruszaja sie pociski gracza
	static const double stalaPredkoscPociskow;

	/// atrybut elapsed umozliwia na obliczenie jaki czas przeminal od poprzedniego kroku obliczen
	sf::Time elapsed;
	/// atrybut CSterowanie (kompozycja), obiekt, ktory umozliwia sterowanie klawiatura
	CSterowanie klaw;

	/// atrybut czasPomiedzyLezkami, ktory pozwala na zmierzenie ile pozostalo czasu do mozliwosci wystrzelenia kolejnego pocisku
	double czasPomiedzyLezkami;

	/*!
	\brief metoda poruszanieKolizjaPostaci(CSterowanie klaw), ktora laczy ze soba metody klasy CPostacGracza : poruszaniePostaci() oraz granicePokoju() oraz sprawdza czy gracz nie przechodzi do nowego pokoju oraz czy na jego drodze nie znajduje sie element otoczenia blokujacy jego ruch
	*/
	void poruszanieKolizjaPostaci();
	/*!
	\brief metoda wystrzel(CSterowanie klaw) umozliwia na wystrzelenie pocisku (tworzymy nowy element w wektorze lezki)
	*/ 
	void wystrzel();
	/*!
	\brief metoda poruszanieLezki() sprawdza czy: najstarsza lezka nie przekroczyla maksymalnego zasiegu, sprawdza czy pocisk nie trafil na granice pokoju, sprawdza czy pocisk nie trafil na element otoczenie lub czy pocisk nie trafil na przeciwnika. Lezki te sa usuwane, a w przypadku trafienia przeciwnika zadawane sa mu obrazenia
	*/
	void poruszanieLezki();
	/*!
	\briefmetoda wygrana() sprawdza czy w danym pokoju, w ktorym jest boss, ten zostal pokonany, jesli tak to umozliwia to nam przejscie do kolejnego poziomu (przejscie postaci do odpowiedniego punktu w pokoju)
	*/
	void wygrana();
	/*!
	\brief metoda podniesieniePrzedmiotu() sprawdza czy gracz jest w pokoju treasure oraz sprawdza czy gracz podniosl przedmiot
	*/
	void podniesieniePrzedmiotu();

public:
	/// atrybut clock, ktory pozwala na pobranie czasu
	sf::Clock clock;
	/// wektor CPociski lezki (kompozycja) i przechowuje informacje o lezkach wystrzelonych przez postac gracza
	std::vector<CPociski> lezki;
	/// atrybut CPostacGracza postac (kompozycja), obiekt ktorym steruje postac
	CPostacGracza postac;
	/// atrybut CPoziom poziom (kompozycja), obiekt po ktorym mozemy sie poruszac
	CPoziom poziom;

	/*!
	\brief metoda dzialanie() laczy w sobie wszystkie obliczenia potrzebne do dzialania gry
	*/
	void dzialanie();
	/*!
	\brief metoda zapisz() powoduje zapisanie postepu stanu gry
	*/
	void zapisz();
	/*!
	\brief metoda wczytaj() powoduje wczytanie postepu stanu gry
	*/
	void wczytaj();
	/*!
	\brief konstrukto CGra() inicjalizuje atrybuty oraz generuje i wczytuje poziomy
	*/
	CGra();
	/*!
	\brief destruktor zapisuje stan gry, przy wylaczeniu gry
	*/
	~CGra();


	void hiperBomba();
};

