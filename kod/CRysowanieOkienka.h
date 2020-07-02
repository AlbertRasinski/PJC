#pragma once
#include "CGra.h"
#include "CMenu.h"
#include <SFML/Audio.hpp>

/// klasa CRysowanieOkienka umozliwia pokazanie uzytkownikowi menu oraz gre

class CRysowanieOkienka
{
private:
	/// struktura TeksturyISprite przechowuje informacje texture oraz sprite
	struct TeksturyISprite {
		sf::Texture texture_;
		sf::Sprite sprite_;
	};

	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsmenu0;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsmenu1;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsmenu4;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tswybor;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPostac[4];
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsBasement;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsLezka;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsTrapdoor;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsKamien1;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsKamien2;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsCzaszka;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsStal;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsSerceCale;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsSercePol;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsSercePuste;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsFly;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsOgien;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsHeadless;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsFlyShooting;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsTurret;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsBossTwins;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsBossFlyMaster;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPociskiPrzecwnik;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsOdkryty;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsNieodkryty;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsObecny;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsBoss;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsTreasure;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPodest;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot1;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot2;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot3;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot4;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot5;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot6;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot7;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot8;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot9;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot10;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPrzedmiot11;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsPokojeTlo;
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsDrzwi[4];
	/// tekstury oraz sprite'y do odpowiednich obiektow
	TeksturyISprite tsDrzwizamkniete[4];

	// atrybut menu (kompozycja), pozwala na obsluge menu i gry
	CMenu menu;

public:
	/*!
	\ metoda rysuj() rysuje na ekranie dane
	*/
	void rysuj();

	/*!
	\ konstruktor CRysowanieOkienka() wczytuje obrazki
	*/
	CRysowanieOkienka();
};

