#pragma once
#include <SFML/Graphics.hpp>

/// klasa CSterowanie umozliwia na wczytanie wcisnietych przyciskow

class CSterowanie
{
public:
	/// atrybut up - przycisk W wcisniety
	bool up;
	/// atrybut down - przycisk S wcisniety
	bool down;
	/// atrybut left - przycisk A wcisniety
	bool left;
	/// atrybut right - przycisk D wcisniety
	bool right;
	/// atrybut shootUp - przycisk strzalka w gore/8 na num pad wcisniety
	bool shootUp;
	/// atrybut shootDown - przycisk strzalka w dol/5 na num pad wcisniety
	bool shootDown;
	/// atrybut shootLeft - przycisk strzalka w lewo/4 na num pad wcisniety
	bool shootLeft;
	/// atrybut shootRight - przycisk strzalka w prawo/6 na num pad wcisniety
	bool shootRight;
	/// atrybut space - przycisk space wcisniety
	bool space;
	/// atrybut enter - przycisk enter wcisniety
	bool enter;
	/// atrybut esc - przycisk esc wcisniety
	bool esc;

	/*!
	\brief metoda zczytajPrzyciski(), ktora wczytuje wcisniete przyciski
	*/
	void sczytajPrzyciski();

	/*!
	\brief konstruktor klasy CSterowanie(), inicjalizuje atrybuty
	*/
	CSterowanie();
};

