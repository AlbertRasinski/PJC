#pragma once
#include "CPolozenie.h"
#include "CZycie.h"
#include "CSterowanie.h"

/// klasa, ktora umozliwia stworzenie obiektow- pociskow

class CPociski
{
public:
	/// atrybut kierunek okresla, w ktorym kierunku poruszaja lezki: do dolu/gory/prawej/lewej
	int kierunek;

	/// atrybut CPolozenie poczatkowePolozeniePociskow (kompozycja) okresla, w ktorym polozeniu x oraz y zostaly wystrzelone (polozenie postaci w chwili wystrzelenie), pozwala na wyliczenie zasiegu
	CPolozenie poczatkowePolozeniePociskow;
	/// atrybut CPolozenie obecnePolozeniePociskow (kompozycja) okresla jakie jest obecne pomieszczenie danego pocisku (w wyniku poruszania lezki)
	CPolozenie obecnePolozeniePociskow;

	/*!
	\brief konstruktor struktury CPociski, inicjuje wartosci atrybutow jakie posiada pocisk

	\param ppx okresla poczatkowePolozeniePociskow w osi x
	\param ppy okresla poczatkowePolozeniePociskow w osi y
	\param opx okresla obecnePolozeniePociskow w osi x
	\param opy okresla obecnePolozeniePociskow w osi y
	\param kierunek_ okresla, w ktorym kierunku porusza sie pocisk
	*/
	CPociski(int ppx, int ppy, int opx, int opy, int kierunek_);
};