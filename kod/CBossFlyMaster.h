#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CBossFlyMaster okresla zachowanie tego typu przeciwnika

class CBossFlyMaster: public CPrzeciwnik
{
private:
	/// statyczna stala czasPomiedzyTworzeniem okresla podstawowy czas pomiedzy kolejnymi momentami gdy boss przywoluje do zycia nowych przeciwnikow
	static const double czasPomiedzyTworzeniem;
	/// statyczna stala czasChodzenie okresla podstawowy czas pomiedzy kolejnymi zmianami kierunku poruszania sie
	static const double czasChodzenie;
	/// statyczna stala predkoscPoruszania okresla parametr pomagajacy okreslic predkosc poruszania sie
	static const double predkoscPoruszania;

	/// atrybut odliczaniePomiedzyTworzeniami odlicza czas jaki pozostal do kolejnego przyzwania przeciwnikow
	double odliczaniePomiedzyTworzeniami;
	/// atrybut odliczanieChodzenie odlicza czas jaki pozostal do kolejnej zmiany kierunku chodzenia
	double odliczanieChodzenie;
	/// atrybut katPoruszania okresla pod jakim katem bedzie sie poruszac przeciwnik
	int katPoruszania;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. co jakis czas zmienia kierunek poruszania i porusza sie zgodnie z nim (jezeli dojdzie do granicy pokoju to sie odbija) oraz co pewien czas przyzywa nowych przeciwnikow
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:

	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CBossFlyMaster oraz atrybutow klasy bazowej
	*/
	CBossFlyMaster(int x, int y);
};

