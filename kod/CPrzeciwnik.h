#pragma once
#include "CPolozenie.h"
#include "CPociski.h"
#include "CZycie.h"

/// klasa CPrzeciwnik jest klasa czysto wirtualna, sluzy do wywolania akcji przeciwnika roznych typow

class CPrzeciwnik
{
public:
	void setZyciePrzeciwnika(int zycie);
	double getPolozeniePrzeciwnikaX();
	double getPolozeniePrzeciwnikaY();
	int getZyciePrzeciwnika();
	int getRozmiarPrzeciwnikaX();
	int getRozmiarPrzeciwnikaY();
	int getPociskiSize();
	double getPociskPozycjaX(int i);
	double getPociskPozycjaY(int i);
	/*!
	\brief metoda zachowaniePrzeciwnika jest funkcja wirtualna, jest nadpisywana przez inna metode o tej samej nazwie klasy pochodnej

	\param	parametr graczX okresla obecne polozenie X postaci gracza
	\param	parametr graczY okresla obecne polozenie Y postaci gracza
	\param	parametr elapsed pozwala na okreslenie ile czasu minelo od poprzedniej tury obliczen
	\param	wektor wskaznikow CPrzeciwnik, pozwala m.in. na przyzwanie nowych przeciwnikow (CBossFlyMaster)
	*/
	virtual void zachowaniePrzeciwnika(int graczX, int graczY, sf::Time elapsed, std::vector<CPrzeciwnik*>& wek) = 0;

private:
	/// atrybut rozmiarX okreslaja jak szeroki jest, sluzy do okreslenia kontaktu postaci gracza z przeciwnikiem oraz hitboxow
	int rozmiarX;
	/// atrybut rozmiarY okreslaja jak wysoki jest, sluzy do okreslenia kontaktu postaci gracza z przeciwnikiem oraz hitboxow
	int rozmiarY;
	/// atrybut CZycie zyciePrzeciwnika ile ma zycia
	CZycie zyciePrzeciwnika;

protected:
	/// atrybut CPolozenie polozeniePrzeciwnika okresla polozenie przeciwnika
	CPolozenie polozeniePrzeciwnika;
	/// wektor CPociski pociskiPrzeciwnika pozwala na strzelanie przez przeciwnika
	std::vector<CPociski> pociskiPrzeciwnika;
	/// wektor CPociski poczatkowePolozenieGracza pozwala na okreslenie kierunku strzalow przeciwnika
	std::vector<CPolozenie> poczatkowePolozenieGracza;

	/*!
	\brief kontruktor klasy, inicjowanie atrybutow

	\param	parametr x okresla polozenie
	\param	parametr y okresla polozenie
	\param	parametr max okresla maksymalne zycie
	\param	parametr max okresla obecne zycie
	\param	parametr rozmiarX_ okresla szerkosc przeciwnika (hitbox+kolizja gracza)
	\param	parametr rozmiarY_ okresla wysokosc przeciwnika (hitbox+kolizja gracza)
	\param	parametr typPrzeciwnika okresla typ przeciwnika
	*/
	CPrzeciwnik(int x, int y, int max, int obecne, int rozmiarX_, int rozmiarY_, char typPrzeciwnika_);
};