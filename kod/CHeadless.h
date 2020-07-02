#pragma once
#include "CPrzeciwnik.h"

/// klasa pochodna (polimorfizm po klasie bazowej CPrzeciwnik ) CFlyShooting okresla zachowanie tego typu przeciwnika

class CHeadless:public CPrzeciwnik
{
private:
	/// statyczna stala czasPomiedzySkokami okresla podstawowy czas pomiedzy kolejnymi momentami gdy przeciwnik skacze
	static const double czasPomiedzySkokami;
	/// statyczna stala predkosc jest pomocna do obliczenia predkosci przeciwnika
	static const double predkosc;
	/// statyczna stala zasieg okresla jak daleko moze skoczyc przeciwnik
	static const int zasieg;

	/// atrybut odliczanie okresla ile pozostalo czasu do kolejnego skoku
	double odliczanie;
	/// atrybut sprawdza, czy przeciwnik nadal jest podczas wykonywania skoku
	bool podczasSkoku;
	/// atrybut pozX pozwala zapamietac pozycje x, do ktorej skoczy przeciwnik
	int pozX;
	/// atrybut pozY pozwala zapamietac pozycje y, do ktorej skoczy przeciwnik
	int pozY;

	/*!
	\ metoda zachowaniePrzeciwnika() przyslania funkcje klasy CPrzeciwnik, okresla jak zachowuje sie nasz przeciwnik. Przeciwnik zazwyczaj stoi, lecz gdy minie pewien przedzial czasu wyskoczy on i bedzie zmierzal do konkretnego punktu. Jak dojdzie do konkretnego punktu znowu czeka na kolejny skok
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek);

public:

	/*!
	\ konstruktor pozwala na inicjalizacje atrybutow klasy CHeadless oraz atrybutow klasy bazowej
	*/
	CHeadless(int x, int y);
};

