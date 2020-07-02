#pragma once
#include "CPolozenie.h"
#include "CZycie.h"
#include "CSterowanie.h"

/// klasa CPostacGracza opisuje obiekt glownej postaci, ktora moze sterowac gracz

class CPostacGracza
{
private:
	/// statyczna stala zmienna czasNiewrazliwosci okresla jaki jest czas pomiedzy kolejnymi mozliwymi momentami przyjecia obrazen przez gracza
	static const double czasNiewrazliwosci;
	/// statyczna stala zmienna stalaPredkoscPostaci pomaga wyliczyc predkosc poruszania sie gracza
	static const double stalaPredkoscPostaci;

public:
	/// atrybut predkosc okresla obecna predkosc poruszania sie postaci
	double predkosc;
	/// atrybut silaAtakow okresla obecne obrazenia pojedynczego pocisku zadawane przez gracza
	double silaAtakow;
	/// atrybut szybkostrzelnosc okresla jak szybko nasza postac moze wystrzelic kolejny pocisk
	double szybkostrzelnosc;
	/// atrybut zasieg okresla jak daleko moga doleciec pociski wystrzelone przez gracza
	double zasieg;
	/// atrybut predkoscPociskow okresla jak szybko sie poruszaja po planszy wystrzelone przez gracza pociski
	double predkoscPociskow;
	/// atrybut wygladPostaci okresla wyglad postaci w zaleznosci w jakim kierunku sie porusza i w ktorym strzela, pomocny przy rysowaniu
	int wygladPostaci;
	/// atrybut obecnePomieszczenieX okresla, w ktorym obecnie pokoju znajduje sie gracz na poziomie, polozenie X 
	int obecnePomieszczenieX;
	/// atrybut obecnePomieszczenieY okresla, w ktorym obecnie pokoju znajduje sie gracz na poziomie, polozenie Y
	int obecnePomieszczenieY;
	/// atrybut odliczanieNiewrazliwosci pozwala, pozwala na wyliczenie czasu jaki pozstal po otrzymaniu obrazenia, po ktorym znowu mozemy byc zranieni
	double odliczanieNiewrazliwosci;
	/// atrybut flying okresla, czy postac gracza moze przelatywac ponad obiektami, ktore normalnie go blokuja
	bool flying;
	/// atrybut shootsThroughWalls okresla, czy pociski gracza moga przelatywac przez 
	bool shootsThroughWalls;



	int stanHiperBomb;



	/// CPolozenie atrybut polozeniePostaci (kompozycja) okresla obecna pozycje x oraz y postaci gracza na plaszczyznie
	CPolozenie polozeniePostaci;
	/// CPolozenie atrybut polozeniePostaciPoczatkowe (kompozycja) okresla, jaka byla pozycja x y postaci gracza w poprzednim kroku wykonywania obliczen, pomaga w okresleniu kolizji postaci z obiektami na planszy
	CPolozenie polozeniePostaciPoczatkowe;
	/// CZycie atrybut zyciePostaci (kompozycja) okresla, jaki jest obecny stan zdrowia oraz jakie jest maksymalne mozliwe zycie postaci gracza
	CZycie zyciePostaci;

	/*!
	\brief konstruktor struktury, inicjuje wartosci atrybutow jakie posiada postac gracza
	*/
	CPostacGracza();

	/*!
	\brief metoda, ktora wczytuje polozeniePostaciPoczatkowe oraz zmienia pozycje i wyglad postaci gracza w zaleznosci od kierunku poruszania (nie sprawdza kolizji)

	\param CSterowanie klaw okresla, ktore przyciski sa obecnie wcisniete
	\param elapsed okresla umozliwia okreslenie jaki czas minal od poprzedniego kroku wykonywania obliczen
	*/
	void poruszaniePostaci(CSterowanie klaw, sf::Time elapsed);
	/*!
	\brief metoda, ktora sprawdza, czy postac nie wykroczyla poza granice pokoju, jesli tak to odpowiednio reaguje
	*/
	void granicePokoju();
	/*!
	\brief metoda, ktora sprawdza czy doszlo do kontaktu z okreslonym przeciwnikiem

	\param	parametr przciwnikX okresla polozenie X przeciwnika na planszy
	\param	parametr przciwnikY okresla polozenie Y przeciwnika na planszy
	\param	parametr rozmiarX okresla ile pikseli od przeciwnika w osi x oznacza ewentualne przyjecie obrazen
	\param	parametr rozmiarY okresla ile pikseli od przeciwnika w osi y oznacza ewentualne przyjecie obrazen
	*/
	bool kolizjaPrzeciwnik(int przeciwnikX, int przeciwnikY, int rozmiarX, int rozmiarY);
};