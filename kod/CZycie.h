#pragma once

/// struktura CZycie przechowuje informacje jakie jest maksymalne zycie danego obiektu oraz jaki jest obecny stan tego zycia

struct CZycie
{
public:
	/// zmienna maksymalneZycie okresla maksymalne zycie obiektu
	int maksymalneZycie;
	/// zmienna obecneZycie okresla ile aktualnie zycia posiada obiekt
	int obecneZycie;


	/*!
	\brief konstruktor struktury, inicjuje wartosci atrybutow maksymalneZycie oraz obecneZycie

	\param maksymalneZycie_	wartosc maksymalnego zycia, ktora wpisujemy do atrybutu maksymalneZycie
	\param pozycjaY_	wartosc obecnego zycia, ktora wpisujemy do atrybutu obecneZycie
	*/
	CZycie(int maksymalneZycie_, int obecneZycie_);
};

