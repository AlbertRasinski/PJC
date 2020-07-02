#pragma once
#include "CSterowanie.h"
#include "CGra.h"

/// klasa Cmenu, ktorej zadaniem jest mozliwosc wygenerownie menu oraz umozliwienie graczowi poruszanie po nim

class CMenu
{
private:
	/// atrybut kontrola okresla czy po wcisnieciu przycisku puscilismy go (jedno klikniecie-jedno przejscie)
	bool kontrola;
	/// atrybut CSterowanie klaw (kompozycja) umozliwia wczytanie przyciskow
	CSterowanie klaw;

	/*!
	\ metoda kontrolaSterowania() umozliwia na sprawdzenie czy przycisk po wcisnieciu zostal puszczony. Pozwala to na zabezpieczenie poruszania sie po menu przed przeskakiwaniem przez kilka opcji
	*/
	void kontrolaSterowania();

public:
	/// atrybut tryb okresla, na ktorym ekranie menu aktualnie sie znajdujemy
	int tryb;
	/// atrybut wybor okresla, ktora opcja w menu jest obecnie zaznaczona
	int wybor;
	/// atrybut CGra gra (agregacja), umozliwia na utworzenie nowej gry/wczytania ostatniego stanu gry 
	CGra* gra;

	/*!
	\ metoda poruszaniePoMenu() okresla w jaki sposob reaguje menu na dzialania uzytkownika
	*/
	void poruszaniePoMenu();

	/*!
	\ konstruktor CMenu inizjalizuje atrybuty klasy
	*/
	CMenu();
	/*!
	\ destruktor ~CMenu sprzata po sobie wkaznik gra
	*/
	~CMenu();
};