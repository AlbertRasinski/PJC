#pragma once
#include "CPolozenie.h"

/// klasa CelementOtoczenia opisuje obiekt na planszy, ktory powoduje, ze gracz nie moze przejsc (np. kamien, czaszka)

class CelementOtoczenia
{
public:
	/// atrybut typOtoczenia okresla jakim rodzajem przeszkody jest dany obiekt
	char typOtoczenia;
	/// atrybut CPolozenie polozenieOtoczenia (kompozycja) okresla w jakiej pozycji xy na plaszczyznie znajduje sie dany obiekt
	CPolozenie polozenieOtoczenia;

	/*!
	\brief konstruktor klasy CelementOtoczenia, ktory inicjalizuje atrybuty obiektu

	\param typOtoczenia przyjmuje wartosc typOtoczenia_
	\param x oznacza polozenie w osi x danego obiektu
	\param y oznacza polozenie w osi y danego obiektu
	*/
	CelementOtoczenia(char typOtoczenia_, int x, int y);
};

