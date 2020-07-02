#pragma once
#include "CelementOtoczenia.h"
#include "CPrzeciwnik.h"
#include "CFly.h"
#include "COgien.h"
#include "CHeadless.h"
#include "CFlyShooting.h"
#include "CTurret.h"
#include "CBossTwins.h"
#include "CBossFlyMaster.h"

/// klasa CPokoj okresla parametry pokoju (poziom sklada sie z pokoi)

class CPokoj
{
public:
	/// obecnosc okresla, czy dany pokoj istnieje (czy na planszy poziomu, w danym miejscu jest jakis pokoj)
	bool obecnosc;
	/// odkryty okresla, czy postac gracza znajdowala sie juz w danym pomieszczeniu
	bool odkryty;
	/// boss okresla, czy w danym pomieszczeniu znajduje sie finalny boss poziomu
	bool boss;
	/// treasure okresla, czy w danym pomieszczeniu znajduje sie pokoj z przedmiotem wzmacniajacym gracza
	bool treasure;
	/// liczbaNiePrzeciwnikow okresla ile jest obiektow w wektorze przeciwnicy, ktorych nie musimy zabic, aby moc przejsc dalej (liczba obiektow typu ogien)
	int liczbaNiePrzeciwnikow;

	/// wektor CelementOtoczenia otoczenie (kompozycja) zbiera w sobie informacje o unikalnych przeszkodach (elementy otoczenia)
	std::vector<CelementOtoczenia> otoczenie;
	/// wektor CPrzeciwnik przeciwnicy (agregacja) zbiera w sobie informacje o unikalnych przeciwnikach w pokoju
	std::vector<CPrzeciwnik*> przeciwnicy;

	/*!
	\brief konstruktor klasy CPokoj, ktory inicjalizuje atrybuty obiektu
	*/
	CPokoj();

	/*!
	\brief detruktor klasy ~CPokoj, ktory sprzata po sobie wskazniki w wektorze przeciwnicy
	*/
	~CPokoj();
};

