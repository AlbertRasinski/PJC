#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CFlyShooting okresla zachowanie tego typu przeciwnika

class CFlyShooting: public CPrzeciwnik
{
private:
	/// statyczna stala czasPomiedzyStrzalami okresla podstawowy czas pomiedzy kolejnymi momentami gdy przeciwnik strzela
	static const double czasPomiedzyStrzalami;
	/// statyczna stala PredkoscFly jest przydatna podczas obliczania predkosci poruszania sie
	static const double PredkoscFly;
	/// statyczna stala predkoscLezkiPrzeciwnika jest przydatna podczas obliczania predkosci poruszania sie pociskow przeciwnika
	static const double predkoscLezkiPrzeciwnika;

	/// atrybut odliczanie okresla ile pozostalo czasu do kolejnego wystrzelenia
	double odliczanie;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. Przeciwnik oddala sie od postaci gracza, co pewien czas strzela pocisk w kierunku postaci gracza 
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:

	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CFlyShooting oraz atrybutow klasy bazowej
	*/
	CFlyShooting(int x, int y);
};

