#pragma once
#include <SFML/Graphics.hpp>

/*!
\brief zmienne globalne

/param wymiarXPlanszyMin okresla lewa granice pokoju
/param wymiarYPlanszyMin okresla gorna granice pokoju
/param wymiarXPlanszyMax okresla prawa granice pokoju
/param wymiarYPlanszyMax okresla dolna granice pokoju
*/
const int wymiarXPlanszyMin = 220;
const int wymiarYPlanszyMin = 150;
const int wymiarXPlanszyMax = 1060;
const int wymiarYPlanszyMax = 570;

/// struktura CPolozenie przechowujaca polozenie x oraz y jakiegos danego obieku

struct CPolozenie
{
public:
	/// zmienna pozycjaX, polozenie w poprzech (wartosc rosnie od lewej do prawej)
	double pozycjaX;
	/// zmienna pozycjaY, polozenie pionowe (wartosc rosnie od gory do dolu)
	double pozycjaY;

	/*!
	\brief konstruktor struktury, inicjuje wartosci atrybutow pozycjaX oraz pozycjaY

	\param pozycjaX_	wartosc osi x, ktora wpisujemy do atrybutu pozycjaX
	\param pozycjaY_	wartosc osi y, ktora wpisujemy do atrybutu pozycjaY
	*/
	CPolozenie(double pozycjaX_, double pozycjaY_);
};

