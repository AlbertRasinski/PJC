#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CBossTwins okresla zachowanie tego typu przeciwnika

class CBossTwins: public CPrzeciwnik
{
private:
	/// statyczna stala czasPomiedzySzarzami okresla podstawowy czas pomiedzy kolejnymi momentami gdy boss zaczyna szarzowac
	static const double czasPomiedzySzarzami;
	/// statyczna stala czasChodzenie okresla podstawowy czas pomiedzy kolejnymi momentami zmiany kierunku poruszania sie
	static const double czasChodzenie;
	/// statyczna stala czasSzarzy okresla podstawowy czas trwania szarzy
	static const double czasSzarzy;
	/// statyczna stala predkoscPoruszania jest przydatna podczas obliczania predkosci poruszania sie
	static const double predkoscPoruszania;
	/// statyczna stala predkoscSzarzy jest przydatna podczas obliczania predkosci szarzowania
	static const double predkoscSzarzy;

	/// atrybut odliczaniePomiedzySzarzami okresla ile pozostalo czasu do kolejnej szarzy
	double odliczaniePomiedzySzarzami;
	/// atrybut odliczanieChodzenie okresla ile pozostalo czasu do kolejnej zmiany poruszania sie
	double odliczanieChodzenie;
	/// atrybut odliczanieSzarza okresla ile pozostalo czasu do konca szarzowania
	double odliczanieSzarza;
	/// atrybut katPoruszania okresla pod jakim katem bedzie sie poruszac przeciwnik
	int katPoruszania;
	/// atrybut namierzenie okresla kat pod jakim boss musi sie poruszac, aby trafic w postac gracza (namierza w momencie rozpoczecia szarzownia)
	bool namierzenie;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. porusza sie planszy i co jakis czas zmienia sie kierunek, w ktorym sie porusza. Co jakis czas zaczyna szarzowac, probujac trafic w postac gracza (namierza na poczatku szarzy) i zaczyna z duza predkoscia pedzic w danym kierunku przez pewien czas. Jezeli trafi na scianke to odbija sie
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:
	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CBossTwins oraz atrybutow klasy bazowej
	*/
	CBossTwins(int x, int y);
};

