#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) COgien okresla zachowanie tego typu przeciwnika

class COgien :public CPrzeciwnik
{
private:
	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. nic nie robi, poprostu jest w danym miejscu i nic nie robi, mo¿e tylko zadaæ obra¿enie jak siê wejdzie na niego
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:
	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy COgien oraz atrybutow klasy bazowej
	*/
	COgien(int x, int y);
};

