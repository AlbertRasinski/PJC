#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CTurret okresla zachowanie tego typu przeciwnika

class CTurret : public CPrzeciwnik
{
private:
	/// statyczna stala czasPomiedzyStrzalami okresla podstawowy czas pomiedzy kolejnymi momentami gdy przeciwnik strzela
	static const double czasPomiedzyStrzalami;
	/// statyczna stala predkoscLezkiPrzeciwnika jest przydatna podczas obliczania predkosci poruszania sie pociskow przeciwnika
	static const double predkoscLezkiPrzeciwnika;

	/// atrybut odliczanie okresla ile pozostalo czasu do kolejnego wystrzelenia
	double odliczanie;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. Przeciwnik nie porusza sie, co pewien czas strzela pocisk w kierunku postaci gracza
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:
	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CFlyShooting oraz atrybutow klasy bazowej
	*/
	CTurret(int x, int y);
};

