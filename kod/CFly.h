#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CFly okresla zachowanie tego typu przeciwnika

class CFly: public CPrzeciwnik
{
private:
	/// statyczna stala PredkoscFly jest przydatna podczas obliczania predkosci poruszania sie
	static const double PredkoscFly;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. Przeciwnik caly czas porusza sie w kierunku gracza
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:
	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CFly oraz atrybutow klasy bazowej
	*/
	CFly(int x, int y);
};

